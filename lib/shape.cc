#include "shape.h"

KPoint parsePoint(Napi::Env* env, Napi::Value point) {
  if (!point.IsObject()) {
    Napi::TypeError::New(*env, "Invalid point format")
      .ThrowAsJavaScriptException();
  }

  Napi::Object obj = point.As<Napi::Object>();
  Napi::Value xx = obj.Get("x");
  Napi::Value yy = obj.Get("y");
  if (!xx.IsNumber() || !yy.IsNumber()) {
    Napi::TypeError::New(*env, "Invalid point format")
      .ThrowAsJavaScriptException();
  }

  int x = xx.As<Napi::Number>().Int32Value();
  int y = yy.As<Napi::Number>().Int32Value();

  return (KPoint) { x, y };
}

KRect parseRect(Napi::Env* env, Napi::Value rect) {
  if (!rect.IsObject()) {
    Napi::TypeError::New(*env, "Invalid rect format")
      .ThrowAsJavaScriptException();
  }

  Napi::Object obj = rect.As<Napi::Object>();
  Napi::Value xx = obj.Get("x");
  Napi::Value yy = obj.Get("y");
  Napi::Value ww = obj.Get("w");
  Napi::Value hh = obj.Get("h");
  if (!xx.IsNumber() || !yy.IsNumber() || !ww.IsNumber() || !hh.IsNumber()) {
    Napi::TypeError::New(*env, "Invalid rect format")
      .ThrowAsJavaScriptException();
  }

  int x = xx.As<Napi::Number>().Int32Value();
  int y = yy.As<Napi::Number>().Int32Value();
  int w = ww.As<Napi::Number>().Int32Value();
  int h = hh.As<Napi::Number>().Int32Value();

  return { x, y, w, h };
}

KColor parseColor(Napi::Env* env, Napi::Value color) {
  if (!color.IsObject()) {
    Napi::TypeError::New(*env, "Invalid color format")
      .ThrowAsJavaScriptException();
  }
  Napi::Object obj = color.As<Napi::Object>();
  Napi::Value rr = obj.Get("r");
  Napi::Value gg = obj.Get("g");
  Napi::Value bb = obj.Get("b");
  Napi::Value aa = obj.Get("a");
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
