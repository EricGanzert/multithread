#include <chrono>
#include <mutex>
#include <thread>
#include <iostream>

using namespace std;
using namespace std::chrono;

milliseconds interval = 50ms;
mutex mtx;
int shared_counter = 0;
int exclusive_counter = 0;

void worker0()
{
    this_thread::sleep_for(interval);
    while(true)
    {
        if (mtx.try_lock())
        {
            ++shared_counter;
            cout << "Shared (" << shared_counter << ")" << endl;
            mtx.unlock();
            return;
        }
        else
        {
            ++exclusive_counter;
            cout << "Exclusive (" << exclusive_counter << ")" << endl;
            this_thread::sleep_for(interval);
        }
    }
}

void worker1()
{
    mtx.lock();
    this_thread::sleep_for(10 * interval);
    ++shared_counter;
    mtx.unlock();
}

int main()
{
    thread t1(worker0);
    thread t2(worker1);
    t1.join();
    t2.join();

    return 0;
}