## 编写一个简单的扩展
1. 新建一个目录 `mkdir first-addon && cd first-addon`
2. 初始化一个node.js项目，执行 "npm init"，接下来输入自己的一些配置
3. 编辑package.json 添加
    '''
    "dependencies": {
        "bindings": "~1.2.1",
        "node-addon-api": "^3.1.0"
    },
    "gypfile": true
    '''
4. 添加 c++ 文件，hello.cpp，编辑binding.gyp, 将 sources 项目中的源代码文件路径改成你自己的路径
6. npm install，这样就会安装所有的扩展依赖。依赖文件为 napi.h 路径在 node_modules/node-addon-api/napi.h，可以自己配置到编辑器中，以便代码提示
6. 编写 hello.cpp，代码惨开,完了以后再次执行 npm install进行编译
```
#include <napi.h>

Napi::String Method(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    return Napi::String::New(env, "Hello world!");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "hello"), Napi::Function::New(env, Method));
    return exports;
}

NODE_API_MODULE(hello, Init)
```
7. 编写 hello.js 文件，代码如下:
```
const bindings = require("bindings");

var addon = require("bindings")("hello");
console.log(addon.hello());
```
8. 执行 node hello.js 就可以输出 hello world. 