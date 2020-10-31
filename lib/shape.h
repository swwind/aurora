#ifndef SHAPE_H
#define SHAPE_H

#include <SDL2/SDL.h>
#include "napi.h"

typedef SDL_Point KPoint;
typedef SDL_Color KColor;
typedef SDL_Rect KRect;

KPoint* parsePoint(const Napi::Value& point);
KRect* parseRect(const Napi::Value& rect);
KColor* parseColor(const Napi::Value& color);

#endif
