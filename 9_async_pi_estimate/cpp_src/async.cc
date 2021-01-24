#include "async.h"
#include "pi_est.h"
#include "napi.h"

class PiWorker : public Napi::AsyncWorker{
public:
    PiWorker(Napi::Function &callback, int points)
        :Napi::AsyncWorker(callback), _points(points), _val(0) {}
    ~PiWorker() {};
    void Execute() {
        _val = esitimate(_points);
    }
    void OnOK() {
        Callback().Call({Env().Undefined(), Napi::Number::New(Env(), _val)});
    }
private:
    int _points;
    double _val;
};

Napi::Value estimatePIAsync(const Napi::CallbackInfo &info) {
    int points = info[0].As<Napi::Number>().Uint32Value();
    Napi::Function callback = info[1].As<Napi::Function>();
    PiWorker *piWorker = new PiWorker(callback, points);
    piWorker->Queue();
    return info.Env().Undefined();
}