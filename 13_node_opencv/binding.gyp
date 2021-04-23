{
  "targets": [
    {
      "target_name": "UmeFaceAlignment",
      "cflags!": [ "-fno-exceptions"],
      "cflags_cc!": [ "-fno-exceptions"],
      "msvs_settings": {
            "VCCLCompilerTool": {
                "AdditionalOptions": [
                    "/std:c++11",
                    "/utf-8",
                ],
            },
        },
      "sources": [
          "cpp_src/face_alignment.cpp",
          "cpp_src/interface.cpp"
        ],
      "libraries": [
          "D:\environment\opencv_4.5\\build\\x64\\vc14\lib\\opencv_world451.lib"
        ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "D:\environment\opencv_4.5\\build\include"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
