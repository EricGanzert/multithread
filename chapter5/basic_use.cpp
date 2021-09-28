#include <iostream>
#include <string>
#include <thread>
#include <utility>

using namespace std;

void worker(int n, string s) {
    cout << "thread " << n << " got parameter: " << s << endl; 
}

int main()
{
    int i = 1;
    string s = "Test";

    thread t0(worker, i, s);
    thread t1(move(t0));
    t1.join();

    return 0;
}