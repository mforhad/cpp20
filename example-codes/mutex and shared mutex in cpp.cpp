#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <utility>
#include <shared_mutex>

int value {0};

void printThreadInfo(const std::vector<std::pair<size_t, int>>& ti) {
    std::cout << "[thread#" << std::hash<std::thread::id>{}(std::this_thread::get_id()) % 10000 << "] Printing thread information.." << std::endl;
    for (auto p: ti) {
        std::cout << p.first << " " << p.second << std::endl;
    }   
}

int main() {
    std::vector<std::jthread> threadPool;
    std::vector<std::pair<size_t, int>> threadInfo;
    std::shared_mutex m;
    
    int numberOfThread = 10;

    // Writers to write threadInfo
    std::cout << "Adding thread number and value to the threadInfo list... " << std::endl;
    for (int t = 1; t <= numberOfThread; t++) {
        threadPool.emplace_back([&] {
            m.lock();
            std::pair<size_t, int> p (std::hash<std::thread::id>{}(std::this_thread::get_id()) % 10000, value++);
            std::cout << "(" << p.first << ", " << p.second << ") Added" <<std::endl;
            threadInfo.emplace_back(p);
            m.unlock();
        });
    }

    // Readers to read threadInfo
    std::cout << "Reading thread info" << std::endl;
    for (int t = 1; t <= numberOfThread; t++) {
        threadPool.emplace_back([&] (const std::vector<std::pair<size_t, int>>& ti) {
            m.lock_shared();
            printThreadInfo(std::ref(ti));
            m.unlock_shared();
        }, std::ref(threadInfo));
    }

    return 0;
}
