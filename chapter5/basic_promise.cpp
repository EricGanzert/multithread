#include <functional>
#include <future>
#include <iostream>
#include <thread>

using namespace std;

void print_it(future<int>& fut)
{
    int x = fut.get();
    cout << "value: " << x << endl;
}

int main()
{
    promise<int> prom;
    future<int> fut = prom.get_future();
    thread th1(print_it, std::ref(fut));

    prom.set_value(10);
    th1.join();
    return 0;
}