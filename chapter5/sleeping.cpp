#include <chrono>
#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

using timepoint = time_point<high_resolution_clock>;

int main()
{
    cout << "Starting sleep." << endl;

    timepoint start = high_resolution_clock::now();
    this_thread::sleep_for(600ms);
    timepoint end = high_resolution_clock::now();

    duration<double, milli> elapsed = end - start;
    cout << "Slept for: " << elapsed.count() << " ms" << endl;

    return 0; 
}