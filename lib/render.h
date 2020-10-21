#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include "napi.h"
#include "keys.h"
#include "shape.h"

namespace RenderCallbacks {

void registerKeyEventCallback(Napi::Env env, const Napi::Function& fn);
void registerMouseEventCallback(Napi::Env env, const Napi::Function& fn);

} // namespace RenderCallbacks

SDL_Texture* loadTexture(std::string path);

namespace Render {

void SetColor(const KColor& color);
void DrawLine(const KPoint& st, const KPoint& ed);
void DrawPoint(const KPoint& p);
void DrawRect(const KRect& r);
void FillRect(const KRect& r);
void RenderPresent();
bool registerTexture(int id, std::string src);
bool init();
void close();
void eventLoop();

} // namespace Render

#endif // RENDER_H
