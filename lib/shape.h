#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>
#include "napi.h"

struct KPoint { int x, y; };
struct KColor { uint8_t r, g, b, a; };
typedef SDL_Rect KRect;

KPoint parsePoint(Napi::Env* env, Napi::Value point);
KRect parseRect(Napi::Env* env, Napi::Value rect);
KColor parseColor(Napi::Env* env, Napi::Value color);

#endif
