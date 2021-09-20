#include "worker.h"
#include "dispatcher.h"

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;


void Worker::getCondition(condition_variable* &cv)
{
    cv = &(this)->cv;
}

void Worker::run() {
    while (running)
    {
        if (ready)
        {
            ready = false;
            request->process();
            request->finish();
        }

        if (Dispatcher::addWorker(this))
        {
            // Use the ready loop to deal with spurious wake-ups
            while (!ready && running)
            {
                if (cv.wait_for(ulock, 1s) == cv_status::timeout)
                {
                    // we timed out, but keep waiting unless
                    // the worker is stopped by the dispatcher
                }
            }
        }
    }
}