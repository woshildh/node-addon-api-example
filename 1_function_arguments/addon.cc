#include "napi.h"

Napi::Value Add(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    if(info.Length() < 2) {
        Napi::Error::New(env, "Wrong number of parameters.").ThrowAsJavaScriptException();
        return env.Null();
    }
    if(!info[0].IsNumber() || !info[1].IsNumber()) {
        Napi::Error::New(env, "Wrong type of parameters.").ThrowAsJavaScriptException();
        return env.Null();
    }
    double arg0 = info[0].ToNumber();
    double arg1 = info[1].ToNumber();

    Napi::Number result = Napi::Number::New(env, arg0 + arg1);
    return result;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "add"), Napi::Function::New(env, Add));
    return exports;
}

NODE_API_MODULE(addon, Init)
