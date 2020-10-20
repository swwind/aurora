#include "napi.h"

struct KColor {
  uint8_t r, g, b, a;
};

KColor parseColor(Napi::Env* env, Napi::Value color) {
  if (!color.IsObject()) {
    Napi::TypeError::New(*env, "Invalid color format")
      .ThrowAsJavaScriptException();
  }

  Napi::Object obj = color.As<Napi::Object>();
  Napi::Value rr = obj.Get(Napi::String::New(*env, "r"));
  Napi::Value gg = obj.Get(Napi::String::New(*env, "g"));
  Napi::Value bb = obj.Get(Napi::String::New(*env, "b"));
  Napi::Value aa = obj.Get(Napi::String::New(*env, "a"));
  if (!rr.IsNumber() || !gg.IsNumber() || !bb.IsNumber() || !aa.IsNumber()) {
    Napi::TypeError::New(*env, "Invalid color format")
      .ThrowAsJavaScriptException();
  }

  // FIXME: maybe dangerous here
  uint8_t r = rr.As<Napi::Number>().Uint32Value();
  uint8_t g = gg.As<Napi::Number>().Uint32Value();
  uint8_t b = bb.As<Napi::Number>().Uint32Value();
  uint8_t a = aa.As<Napi::Number>().Uint32Value();

  return (KColor) { r, g, b, a };
}
