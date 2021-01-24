#include "myobject.h"
#include "napi.h"

Napi::Object MyObject::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(
        env, "MyObject",
        {  InstanceMethod("plusOne", &MyObject::plusOne), 
        InstanceMethod("value", &MyObject::getValue),
        InstanceMethod("multiply", &MyObject::multiply)  }
    );

    Napi::FunctionReference *constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    env.SetInstanceData(constructor);

    exports.Set("MyObject", func);
    return exports;
}

MyObject::MyObject(const Napi::CallbackInfo &info): Napi::ObjectWrap<MyObject>(info)
{
    Napi::Env env = info.Env();
    int length = info.Length();
    if(length < 1 || !info[0].IsNumber()) {
        Napi::TypeError::New(env, "Wrong parameters").ThrowAsJavaScriptException();
        return ;
    }
    Napi::Number number = info[0].ToNumber();
    _value = number.DoubleValue();
}

Napi::Value MyObject::getValue(const Napi::CallbackInfo &info) {
    return Napi::Number::New(info.Env(), this->_value);
}

Napi::Value MyObject::plusOne(const Napi::CallbackInfo &info) {
    this->_value += 1;
    return Napi::Number::New(info.Env(), this->_value);
}

Napi::Value MyObject::multiply(const Napi::CallbackInfo &info) {
    Napi::Number mul;
    if(info.Length() < 1 || !info[0].IsNumber()) {
        mul = Napi::Number::New(info.Env(), 1);
    } else {
        mul = info[0].As<Napi::Number>();
    }
    Napi::Object obj = info.Env().GetInstanceData<Napi::FunctionReference>()->New(
        {Napi::Number::New(info.Env(), this->_value * mul.DoubleValue())}
    );
    return obj;
}