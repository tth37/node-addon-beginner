#include "hello.hpp"
#include <napi.h>

Napi::String nodeGetHello(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    auto str = Hello::getHello();
    return Napi::String::New(env, str);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("getHello", Napi::Function::New(env, nodeGetHello));
    return exports;
}

NODE_API_MODULE(ADDON, Init)