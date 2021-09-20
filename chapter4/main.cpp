#include "dispatcher.h"
#include "request.h"

#include <iostream>
#include <string>
#include <csignal>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

sig_atomic_t signal_caught = 0;
mutex logMutex;

void sigint_handler(int /*sig*/) {
    signal_caught = 1;
}

void logFunc(string text) {
    logMutex.lock();
    cout << text << endl;
    logMutex.unlock();
}

int main() {
    signal(SIGINT, &sigint_handler);
    Dispatcher::init(10);

    cout << "Initialised." << endl;
    int cycles = 0;
    Request* rq = 0;
    while (!signal_caught && cycles < 50) {
        rq = new Request();
        rq->setValue(cycles);
        rq->setOutput(&logFunc);
        Dispatcher::addRequest(rq);
        cycles++;
    }

    this_thread::sleep_for(5s);
    Dispatcher::stop();

    cout << "Clean-up done." << endl;
    return 0;
}