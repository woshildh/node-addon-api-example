#include "pi_est.h"
#include "sync.h"
#include <napi.h>

Napi::Value estimatePISync(const Napi::CallbackInfo &info) {
    int points = info[0].As<Napi::Number>().Uint32Value();
    double pi = esitimate(points);
    return Napi::Number::New(info.Env(), pi);
}
