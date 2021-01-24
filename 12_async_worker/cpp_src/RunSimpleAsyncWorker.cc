#include "SimpleAsyncWorker.h"

Napi::Value runSimpleAsyncWorker(const Napi::CallbackInfo &info) {
    int runTime = info[0].As<Napi::Number>().DoubleValue();
    Napi::Function callback = info[1].As<Napi::Function>();
    SimpleAsyncWorker *asyncWorker = new  SimpleAsyncWorker(callback, runTime);
    asyncWorker->Queue(); //加入到队列中去执行
    std::string msg = "SimpleAsyncWorker for " + std::to_string(runTime) + " seconds queued.";
    return Napi::String::New(info.Env(), msg);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "runSimpleAsyncWorker"), 
        Napi::Function::New(env, runSimpleAsyncWorker, "runSimpleAsyncWorker"));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)
