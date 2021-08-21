#include <pthread.h>
#include <stdlib.h>
#include <iostream>
#define NUM_THREADS 5

using namespace std;

void* worker(void* arg)
{
    int value = *((int*) arg);
    (void)value;
    return 0;
}

int main(int /* argc */, char** /* argv */) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code;

    for (unsigned int i = 0; i < NUM_THREADS; ++i)
    {
        thread_args[i] = i;
        result_code = pthread_create(&threads[i], 0, worker, (void*) &thread_args[i]);
        cout << "thread " << i << (!result_code ? " launched successfully" : " failed to launch") << endl;
    }

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        result_code = pthread_join(threads[i], 0);
        cout << "thread " << i << (!result_code ? " joined successfully" : " failed to join") << endl;
    }

    exit(0);
}