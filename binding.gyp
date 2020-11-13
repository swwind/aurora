{
  "targets": [
    {
      "target_name": "aurora",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "aurora.cc",
        "lib/keys.cc",
        "lib/shape.cc",
        "lib/render.cc",
        "lib/worker.cc"
      ],
      "include_dirs": [
        "D:\\lib\\SDL2-devel-2.0.12-VC\\SDL2-2.0.12\\include",
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "conditions": [
        ['OS=="linux"', {
          "libraries": [
            "-lSDL2",
            "-lSDL2_image",
            "-lSDL2_ttf",
            "-lSDL2_mixer"
          ]
        }],
        ['OS=="win"', {
          "libraries": [
            "-l D:\\lib\\SDL2-devel-2.0.12-VC\\SDL2-2.0.12\\lib\\x64\\SDL2",
            "-l D:\\lib\\SDL2-devel-2.0.12-VC\\SDL2-2.0.12\\lib\\x64\\SDL2_image",
            "-l D:\\lib\\SDL2-devel-2.0.12-VC\\SDL2-2.0.12\\lib\\x64\\SDL2_ttf",
            "-l D:\\lib\\SDL2-devel-2.0.12-VC\\SDL2-2.0.12\\lib\\x64\\SDL2_mixer"
          ]
        }]
      ]
    }
  ]
}