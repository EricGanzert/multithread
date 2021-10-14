#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<long long> count;

void worker() {
    count.fetch_add(1, memory_order_relaxed);
}

int main()
{
    thread t1(worker);
    thread t2(worker);
    thread t3(worker);
    thread t4(worker);
    thread t5(worker);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout << "count value: " << count << endl;
}