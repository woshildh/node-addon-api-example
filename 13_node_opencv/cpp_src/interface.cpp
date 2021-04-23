#include <napi.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "face_alignment.h"

Napi::Value FaceAlignment(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    // 检查参数个数
    if(info.Length() < 2) {
        Napi::Error::New(env, "Wrong number of parameters. Need 2 parameters.").ThrowAsJavaScriptException();
        return env.Null();
    }
    // 检查参数类型
    if(!info[0].IsBuffer() || !info[1].IsBuffer()) {
        Napi::Error::New(env, "Wrong type of parameters. Need Buffer.").ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::Object result = Napi::Object::New(info.Env());
    try {
        // 获取参数
        Napi::Buffer<float> bufSrc = info[0].As<Napi::Buffer<float>>();
        Napi::Buffer<float> bufDst = info[1].As<Napi::Buffer<float>>();
        // 检查长度
        if(bufSrc.Length() != 10 || bufDst.Length() != 10) {
            Napi::Error::New(env, "Wrong length of parameters. Need Buffer length is 10.").ThrowAsJavaScriptException();
            return env.Null();
        }
        // 组装 Mat
        cv::Mat matSrc(5, 2, CV_32F, bufSrc.Data());
        cv::Mat matDst(5, 2, CV_32F, bufDst.Data());
        // std::cout<<matSrc.rows<<" , "<<matSrc.cols<<std::endl;
        // std::cout<<matSrc.at<float>(0, 0)<<" "<<matSrc.at<float>(4, 1)<<std::endl;
        // std::cout<<matDst.at<float>(0, 0)<<" "<<matDst.at<float>(4, 1)<<std::endl;
        // 调用结果
        cv::Mat affineMatrix = UmeyamaEstimate(matSrc, matDst);
        float *buf = reinterpret_cast<float*>(affineMatrix.data);
        // std::cout<<affineMatrix.rows<<" "<<affineMatrix.cols<<std::endl;
        // 返回结果
        // 设置仿射矩阵六个值
        Napi::Array array = Napi::Array::New(info.Env(), 6);
        for(int i = 0; i < 6; ++i) {
            float val = buf[i];
            array.Set(Napi::Number::New(info.Env(), i), Napi::Number::New(info.Env(), val));  
        }
        result["affine"] = array;
        result["status"] = 1; // 设置状态成功
    } catch(std::exception &e) {
        // 打印异常
        std::cout<<e.what()<<std::endl;
        result["status"] = 0;
    }
    return result;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "FaceAlignment"), Napi::Function::New(env, FaceAlignment));
    return exports;
}

NODE_API_MODULE(UMEFaceAlignment, Init)
