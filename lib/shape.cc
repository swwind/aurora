#include "shape.h"

KPoint* parsePoint(const Napi::Value& point) {
  if (!point.IsObject()) {
    return NULL;
  }

  Napi::Object obj = point.As<Napi::Object>();
  Napi::Value xx = obj.Get("x");
  Napi::Value yy = obj.Get("y");
  if (!xx.IsNumber() || !yy.IsNumber()) {
    return NULL;
  }

  int x = xx.As<Napi::Number>().Int32Value();
  int y = yy.As<Napi::Number>().Int32Value();

  return new KPoint({ x, y });
}

KRect* parseRect(const Napi::Value& rect) {
  if (!rect.IsObject()) {
    return NULL;
  }

  Napi::Object obj = rect.As<Napi::Object>();
  Napi::Value xx = obj.Get("x");
  Napi::Value yy = obj.Get("y");
  Napi::Value ww = obj.Get("w");
  Napi::Value hh = obj.Get("h");
  if (!xx.IsNumber() || !yy.IsNumber() || !ww.IsNumber() || !hh.IsNumber()) {
    return NULL;
  }

  int x = xx.As<Napi::Number>().Int32Value();
  int y = yy.As<Napi::Number>().Int32Value();
  int w = ww.As<Napi::Number>().Int32Value();
  int h = hh.As<Napi::Number>().Int32Value();

  return new KRect({ x, y, w, h });
}

KColor* parseColor(const Napi::Value& color) {
  if (!color.IsObject()) {
    return NULL;
  }
  Napi::Object obj = color.As<Napi::Object>();
  Napi::Value rr = obj.Get("r");
  Napi::Value gg = obj.Get("g");
  Napi::Value bb = obj.Get("b");
  Napi::Value aa = obj.Get("a");
  if (!rr.IsNumber() || !gg.IsNumber() || !bb.IsNumber() || !aa.IsNumber()) {
    return NULL;
  }

  // FIXME: maybe dangerous here
  uint8_t r = rr.As<Napi::Number>().Uint32Value();
  uint8_t g = gg.As<Napi::Number>().Uint32Value();
  uint8_t b = bb.As<Napi::Number>().Uint32Value();
  uint8_t a = aa.As<Napi::Number>().Uint32Value();

  return new KColor({ r, g, b, a });
}
