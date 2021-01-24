#ifndef _MYOBJECT_H_
#define _MYOBJECT_H_

#include "napi.h"

class MyObject: public Napi::ObjectWrap<MyObject> {
   
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    static Napi::Object NewInstance(Napi::Env, Napi::Value arg);
    MyObject(const Napi::CallbackInfo &info);

private:
    Napi::Value PlusOne(const Napi::CallbackInfo &info);
    double counter_;
};

#endif // _MYOBJECT_H_
