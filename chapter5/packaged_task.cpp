#include <iostream>
#include <future>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

int countdown(int from, int to)
{
    for (int i = from; i < to; i++)
    {
        cout << i << endl;
        this_thread::sleep_for(100ms);
    }

    cout << "Finished countdown" << endl;
    return (to - from) * 100;
}

int main()
{
    packaged_task<int(int,int)> task(countdown);
    future<int> result = task.get_future();
    thread t(move(task), 0, 10);

    int value = result.get();

    cout << "The countdown lasted for " << value << " milliseconds." << endl;

    t.join();
    return 0;
}