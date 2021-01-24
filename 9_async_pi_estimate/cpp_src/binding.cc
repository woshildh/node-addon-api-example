#include "async.h"
#include "sync.h"
#include <napi.h>

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "estimatePISync"),
        Napi::Function::New(env, estimatePISync));
    exports.Set(Napi::String::New(env, "estimatePIAsync"),
        Napi::Function::New(env, estimatePIAsync));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)