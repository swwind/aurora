#include <SDL2/SDL.h>
#include "napi.h"

typedef SDL_Rect KRect;

KRect parseRect(Napi::Env* env, Napi::Value rect) {
  if (!rect.IsObject()) {
    Napi::TypeError::New(*env, "Invalid rect format")
      .ThrowAsJavaScriptException();
  }

  Napi::Object obj = rect.As<Napi::Object>();
  Napi::Value xx = obj.Get(Napi::String::New(*env, "x"));
  Napi::Value yy = obj.Get(Napi::String::New(*env, "y"));
  Napi::Value ww = obj.Get(Napi::String::New(*env, "w"));
  Napi::Value hh = obj.Get(Napi::String::New(*env, "h"));
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
