#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex globalMutex;

void worker(int i) {
    globalMutex.lock();
    cout << "Outputting this from thread number " << i << endl;
    globalMutex.unlock();
}

int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    t1.join();
    t2.join();
    return 0;
}