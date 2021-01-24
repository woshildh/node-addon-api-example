#include "SimpleAsyncWorker.h"
#include <chrono>
#include <thread>
#include <iostream>

SimpleAsyncWorker::SimpleAsyncWorker(Napi::Function& callback, int runTime) 
    : Napi::AsyncWorker(callback), _runTime(runTime) {};

void SimpleAsyncWorker::Execute() {
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(_runTime));
        std::cout<<"============="<<std::endl;
    }
    // if(_runTime == 4) {
    //     SetError("Oops! Failed after 'working' 4 seconds."); // 设置错误之后，Env() 中会有反应
    // }
}

void SimpleAsyncWorker::OnOK() {
    std::string msg = "SimpleAsyncWorker returning after 'working' " +
                    std::to_string(_runTime) + " seconds.";
    Callback().Call( {Env().Null(), Napi::String::New(Env(), msg)} );
}