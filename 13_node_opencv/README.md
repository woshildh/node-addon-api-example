## 安装opencv4nodejs时，设置使用自己的 opencv 环境
1. 安装 cmake
2. 设置环境变量
    set OPENCV4NODEJS_DISABLE_AUTOBUILD=1
    set OPENCV_LIB_DIR=D:\environment\opencv_4.5\build\x64\vc14\lib
    set OPENCV_INCLUDE_DIR=D:\environment\opencv_4.5\build\include
    set OPENCV_BIN_DIR=D:\environment\opencv_4.5\build\x64\vc14\bin
3. npm install -g opencv4nodejs

