#include "request.h"

using namespace std;

void Request::process()
{
    outFnc("Starting processing request " + to_string(value) + "...");
}

void Request::finish()
{
    outFnc("Finished request " + to_string(value));
}