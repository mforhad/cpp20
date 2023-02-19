#include <iostream>
#include <thread>

/*
* This program creates two thread. after 5 seconds, the second thread request
* the first thread to stop.
*/
int main() {
    std::jthread thread1 ( [] (std::stop_token stoken) {
        int counter{0};
        while(1) { // create an infinite loop;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (stoken.stop_requested())
                return;
            std::cout << "Thread1 Counter: " << ++counter << std::endl;
        }
    });

    std::jthread thread2([] (std::jthread& thread1){
        std::this_thread::sleep_for(std::chrono::seconds(5));
        thread1.request_stop();
        std::cout<<"Thread2 request the thread1 to stop." <<std::endl;
    }, std::ref(thread1));

    return 0;
}

// ####### Output #########33
// Thread1 Counter: 1
// Thread1 Counter: 2
// Thread1 Counter: 3
// Thread1 Counter: 4
// Thread2 request the thread1 to stop.
