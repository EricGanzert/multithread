#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <utility>

using namespace std;
using namespace std::chrono;

mutex display_mutex;

void worker()
{
    thread::id this_id = this_thread::get_id();

    display_mutex.lock();
    cout << "thread " << this_id << " sleeping..." << endl;
    display_mutex.unlock();

    this_thread::sleep_for(500ms);
}

int main()
{
    thread t1(worker);
    thread::id t1_id = t1.get_id();

    thread t2(worker);
    thread::id t2_id = t2.get_id();

    display_mutex.lock();
    cout << "t1's id: " << t1_id << endl;
    cout << "t2's id: " << t2_id << endl;
    display_mutex.unlock();

    t1.join();
    t2.join();

    return 0;
}