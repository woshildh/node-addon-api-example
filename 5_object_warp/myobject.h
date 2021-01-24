#ifndef _MYOBJECT_H_
#define _MYOBJECT_H_

#include<napi.h>

class MyObject: public Napi::ObjectWrap<MyObject> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    MyObject(const Napi::CallbackInfo &info);
private:
    Napi::Value getValue(const Napi::CallbackInfo &info);
    Napi::Value plusOne(const Napi::CallbackInfo &info);
    Napi::Value multiply(const Napi::CallbackInfo &info);

    double _value;
};

#endif //_MYOBJECT_H_