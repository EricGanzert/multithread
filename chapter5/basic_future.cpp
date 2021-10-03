#include <iostream>
#include <future>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool is_prime(int x)
{
    for (int i=2; i<x; ++i)
    {
        if (x%i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    future<bool> fut = async(is_prime, 444444448);
    cout << "checking... please wait" << endl;

    milliseconds span = 100ms;
    while(fut.wait_for(span) == future_status::timeout)
    {
        cout << "." << flush;
    }

    bool x = fut.get();
    cout << endl << "444444448 is " << (x?"is":"is not") << " prime." << endl;

    return 0;
}