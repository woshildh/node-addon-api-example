#ifndef _SIMPLEASYNCWORKER_H_
#define _SIMPLEASYNCWORKER_H_

#include <napi.h>

class SimpleAsyncWorker: public Napi::AsyncWorker {
public:
    SimpleAsyncWorker(Napi::Function& callback, int runTime);
    virtual ~SimpleAsyncWorker() {};

    void Execute();
    void OnOK();

private:
    int _runTime;
};

#endif // _SIMPLEASYNCWORKER_H_
