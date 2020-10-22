#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>
#include "napi.h"

struct KPoint { int x, y; };
struct KColor { uint8_t r, g, b, a; };
typedef SDL_Rect KRect;

KPoint* parsePoint(const Napi::Value& point);
KRect* parseRect(const Napi::Value& rect);
KColor* parseColor(const Napi::Value& color);

#endif
