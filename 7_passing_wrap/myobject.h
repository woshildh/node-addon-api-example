#ifndef _MYOBJECT_H_
#define _MYOBJECT_H_

#include "napi.h"

class MyObject: public Napi::ObjectWrap<MyObject> {

public:
    static void Init(Napi::Env env, Napi::Object exports);
    static Napi::Object NewInstance(Napi::Env env, Napi::Value arg);
    double Val() const {return val_;}
    MyObject(const Napi::CallbackInfo &info);

private:
    double val_;
};

#endif // _MYOBJECT_H_
