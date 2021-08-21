#include <pthread.h>
#include <stdlib.h>
#include <iostream>
#define NUM_THREADS 5

static pthread_mutex_t func_mutex = PTHREAD_MUTEX_INITIALIZER;

using namespace std;

void protected_cout(string message)
{
    pthread_mutex_lock(&func_mutex);
    cout << message << endl;
    pthread_mutex_unlock(&func_mutex);
}

void* worker(void* arg)
{
    int value = *((int*) arg);
    string message = "thread value " + to_string(value);
    protected_cout(message);
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
        string message = "thread " + to_string(i) + (!result_code ? " launched successfully" : " failed to launch");
        protected_cout(message);
    }

    for (int i = 0; i < NUM_THREADS; ++i)
    {
        result_code = pthread_join(threads[i], 0);
        string message = "thread " + to_string(i) + (!result_code ? " joined successfully" : " failed to join");
        protected_cout(message);
    }

    exit(0);
}