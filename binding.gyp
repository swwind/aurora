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
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      "link_settings": {
        "libraries": [
          "-lSDL2",
          "-lSDL2_image",
          "-lSDL2_ttf",
          "-lSDL2_mixer"
        ]
      }
    }
  ]
}