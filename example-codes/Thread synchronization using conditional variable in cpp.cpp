#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

const int NUMBER_OF_PRODUCT = 10;

std::queue<int> data;
std::mutex data_mutex;
std::condition_variable conditional_v;

void produce() {
    for (int i = 0; i <= NUMBER_OF_PRODUCT; ++i) {
        // Lock. You do not need to notify while locking. Notify after unlocking
        std::unique_lock<std::mutex> lock(data_mutex);
        data.push(i);
        
        std::cout << "Producer produced " << i << std::endl;

        // unlock and then notify
        lock.unlock();
        conditional_v.notify_one();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consume() {
    while (true) {
        std::unique_lock<std::mutex> lock(data_mutex);
        conditional_v.wait(lock, []{ 
            return !data.empty(); 
        });
        
        int value = data.front();
        data.pop();
        
        lock.unlock();

        std::cout << "Consumer consumed " << value << std::endl;

        if (value == NUMBER_OF_PRODUCT) {
            break;
        }
    }
}

int main() {
    std::thread producerThread(produce);
    std::thread consumerThread(consume);

    producerThread.join();
    consumerThread.join();

    return 0;
}


// ####### Output #######
// Producer produced 0
// Consumer consumed 0
// Producer produced 1
// Consumer consumed 1
// Producer produced 2
// Consumer consumed 2
// Producer produced 3
// Consumer consumed 3
// Producer produced 4
// Consumer consumed 4
// Producer produced 5
// Consumer consumed 5
// Producer produced 6
// Consumer consumed 6
// Producer produced 7
// Consumer consumed 7
// Producer produced 8
// Consumer consumed 8
// Producer produced 9
// Consumer consumed 9
// Producer produced 10
// Consumer consumed 10
  
