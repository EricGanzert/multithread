#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

int counter = 0;
mutex counter_mutex;

void worker()
{
    lock_guard<mutex> lock(counter_mutex);
    if (counter == 1)
    {
        counter += 10;
    }
    else if (counter >= 10)
    {
        counter += 15;
    }
    else if (counter >= 50)
    {
        return;
    }
    else
    {
        ++counter;
    }

    cout << this_thread::get_id() << ": " << counter << endl;
}

int main()
{
    cout << __func__ << ": " << counter << endl;

    thread t1(worker);
    thread t2(worker);
    t1.join();
    t2.join();

    return 0;
}