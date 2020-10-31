#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <map>
#include "napi.h"
#include "keys.h"
#include "shape.h"

struct KTexture {
  int id, width, height;
};
struct KFont {
  int id, size;
};
struct KMusic {
  int id;
};
struct KSound {
  int id;
};

namespace RenderCallbacks {

void registerKeyEventCallback(Napi::Env env, const Napi::Function& fn);
void registerMouseEventCallback(Napi::Env env, const Napi::Function& fn);
void registerWindowEventCallback(Napi::Env env, const Napi::Function& fn);

} // namespace RenderCallbacks

namespace Render {

void SetColor(const KColor* color);
void DrawLine(const KPoint* st, const KPoint* ed);
void DrawPoint(const KPoint* p);
void DrawRect(const KRect* r);
void FillRect(const KRect* r);
void DrawImage(const int& tid, const KRect* srcrect, const KRect* dstrect);
void RenderPresent();

KTexture* registerTexture(std::string src);
KMusic* registerMusic(std::string src);
KSound* registerSound(std::string src);
KFont* registerFont(std::string src, int size);
KTexture* renderText(const int& fid, std::string text, KColor* color, const __uint32_t& length);

void deleteTexture(const int& texture_id);
void deleteFont(const int& font_id);
void deleteMusic(const int& music_id);
void deleteSound(const int& sound_id);

void setTextureAlpha(const int& texture_id, const __int8_t& alpha);

bool init(const char *title, int x, int y, int w, int h, Uint32 flags);
void quit();
void close();
void eventLoop();
void playMusic(const int& mid, const int& times);
void pauseMusic();
void resumeMusic();
void toggleMusic();
void playSound(const int& sid, const int& channel, const int& loops);

} // namespace Render

#endif // RENDER_H
