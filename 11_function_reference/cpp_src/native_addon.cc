#include "native_addon.h"
#include <napi.h>
#include <iostream>

Napi::FunctionReference NativeAddon::constructor;

Napi::Object NativeAddon::Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "NativeAddon",
        { InstanceMethod("tryCallByStoredReference", &NativeAddon::TryCallByStoredReference),
          InstanceMethod("tryCallByStoredFunction", &NativeAddon::TryCallByStoredFunction)});
    constructor = Napi::Persistent(func);
    constructor.SuppressDestruct(); // 阻止指向的元素析构，就是不让func析构
    exports.Set("NativeAddon", func);
    return exports;
}

NativeAddon::NativeAddon(const Napi::CallbackInfo &info) 
    :Napi::ObjectWrap<NativeAddon>(info) {
    jsFnRef = Napi::Persistent(info[0].As<Napi::Function>());
    jsFn = info[1].As<Napi::Function>(); // 直接用是无效的，出了构造函数的范围之后就无效了
}

void NativeAddon::TryCallByStoredReference(const Napi::CallbackInfo &info) {
    jsFnRef.Call({});
}

void NativeAddon::TryCallByStoredFunction(const Napi::CallbackInfo &info) {
    jsFn.Call({});
}
