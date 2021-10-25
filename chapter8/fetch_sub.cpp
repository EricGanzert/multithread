#include <string>
#include <thread>
#include <vector>
#include <iostream>
#include <atomic>
#include <numeric>

using namespace std;

const int N = 10000;
atomic<int> cnt;
vector<int> myData(N);

void reader(int id) {
    for (;;) 
    {
        int idx = atomic_fetch_sub_explicit(&cnt, 1, memory_order_relaxed);
        if (idx >= 0)
        {
            cout << "reader " << to_string(id) << " processed item " 
            << myData[id] << endl;
        }
        else
        {
            cout << "reader " << to_string(id) << " done" << endl;
            break;
        }
    }
}

int main()
{
    fill(myData.begin(), myData.end(), 1);
    cnt = myData.size() - 1;
    vector<thread> v;

    for (int n = 0; n < 10; ++n)
    {
        v.emplace_back(reader, n);
    }

    for (thread& t : v)
    {
        t.join();
    }
}
