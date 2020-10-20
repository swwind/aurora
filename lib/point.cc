#include "napi.h"

struct KPoint {
  int x, y;
};

KPoint parsePoint(Napi::Env* env, Napi::Value point) {
  if (!point.IsObject()) {
    Napi::TypeError::New(*env, "Invalid point format")
      .ThrowAsJavaScriptException();
  }

  Napi::Object obj = point.As<Napi::Object>();
  Napi::Value xx = obj.Get(Napi::String::New(*env, "x"));
  Napi::Value yy = obj.Get(Napi::String::New(*env, "y"));
  if (!xx.IsNumber() || !yy.IsNumber()) {
    Napi::TypeError::New(*env, "Invalid point format")
      .ThrowAsJavaScriptException();
  }

  int x = xx.As<Napi::Number>().Int32Value();
  int y = yy.As<Napi::Number>().Int32Value();

  return (KPoint) { x, y };
}
