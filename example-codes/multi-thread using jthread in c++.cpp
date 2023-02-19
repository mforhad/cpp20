#include <iostream>
#include <thread>
#include <vector>

// just to execute some function by a thread
// multiple thread is writing to the console
void printNumbers(int t) {
    for(int i = 1; i <= t; i++) {
        std::cout << "thread#" << std::this_thread::get_id() << " : " << i << std::endl<<std::endl;
    }
}

int main() {
    std::vector<std::jthread> threadPool;

    int numberOfThread = 5;
    // Create 5 jthreads
    // If you create jthread instead of thread, you do not need to join() them explicitly
    for (int t = 0; t < numberOfThread; t++) {
        // emplace_back() is more efficient as it does not make a copy of the value/object
        threadPool.emplace_back([t] { // added a parameter less lambda to the thread
            printNumbers(t);
        });
    }

    return 0;
}
