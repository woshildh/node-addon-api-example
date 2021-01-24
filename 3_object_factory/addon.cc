#include "napi.h"

int id = 1000;

Napi::Object CreateObject(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Napi::Object obj = Napi::Object::New(env);
    if(info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of parameters").ThrowAsJavaScriptException();
        return obj;
    }
    obj.Set(Napi::String::New(env, "id"), Napi::Number::New(env, id++));
    obj.Set(Napi::String::New(env, "name"), info[0].ToString());
    obj.Set(Napi::String::New(env, "age"), info[1].ToNumber());
    return obj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    return Napi::Function::New(env, CreateObject, "CreateObject");
}

NODE_API_MODULE(addon, Init)