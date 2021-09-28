#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

void worker() {
    this_thread::sleep_for(500ms);
}

int main()
{
    thread t1(worker);
    thread t2(worker);

    cout << "thread 1 id: " << t1.get_id() << endl;
    cout << "thread 2 id: " << t2.get_id() << endl;
    swap(t1, t2);
    cout << "Swapping threads..." << endl;

    cout << "thread 1 id: " << t1.get_id() << endl;
    cout << "thread 2 id: " << t2.get_id() << endl;
    t1.swap(t2);
    cout << "Swapping threads..." << endl;

    cout << "thread 1 id: " << t1.get_id() << endl;
    cout << "thread 2 id: " << t2.get_id() << endl;
    t1.join();
    t2.join();

    return 0;
}