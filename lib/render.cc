#include "render.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

std::map<int, SDL_Texture*> textureMap;
std::map<int, TTF_Font*> fontMap;
int tcnt = 0, fcnt = 0;

std::vector<Napi::ThreadSafeFunction>
	keyEventCallbackList,
	mouseEventCallbackList,
	windowEventCallbackList;

KTexture* addTexture(SDL_Texture* texture, int width, int height) {
	int id = ++ tcnt;
  textureMap.insert(std::make_pair(id, texture));
  return new KTexture({ id, width, height });
}
KFont* addFont(TTF_Font* font, int size) {
	int id = ++ fcnt;
  fontMap.insert(std::make_pair(id, font));
  return new KFont({ id, size });
}

void keyEventCallback(Napi::Env env, Napi::Function fn, SDL_Event* e) {
	Napi::Object result = Napi::Object::New(env);
	result["type"] = getEventType(e);
	result["keycode"] = e->key.keysym.sym;
	result["key"] = getKeyCode(e->key.keysym.sym);

	fn.Call({ result });
	delete e;
}
void mouseEventCallback(Napi::Env env, Napi::Function fn, SDL_Event* e) {
	int x, y;
	SDL_GetMouseState(&x, &y);

	Napi::Object result = Napi::Object::New(env);
	result["type"] = getEventType(e);
	result["x"] = x;
	result["y"] = y;

	if (e->type == SDL_MOUSEWHEEL) {
		result["dx"] = e->wheel.x;
		result["dy"] = e->wheel.y;
	}

	if (e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		result["button"] = getMouseType(e->button.button);
	}

	fn.Call({ result });
	delete e;
}
void windowEventCallback(Napi::Env env, Napi::Function fn, SDL_Event* e) {
	Napi::Object result = Napi::Object::New(env);
	result["type"] = getEventType(e);

	if (e->type == SDL_WINDOWEVENT) {
		if (e->window.event == SDL_WINDOWEVENT_RESIZED || e->window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
			result["w"] = e->window.data1;
			result["h"] = e->window.data2;
		}
		if (e->window.event == SDL_WINDOWEVENT_MOVED) {
			result["x"] = e->window.data1;
			result["y"] = e->window.data2;
		}
	}

	fn.Call({ result });
	delete e;
}

void RenderCallbacks::registerKeyEventCallback(Napi::Env env, const Napi::Function& fn) {
	keyEventCallbackList.push_back(Napi::ThreadSafeFunction::New(
		env, fn, "Emilia saikou!!", 0, 1,
		[] (Napi::Env) { }
	));
}
void RenderCallbacks::registerMouseEventCallback(Napi::Env env, const Napi::Function& fn) {
	mouseEventCallbackList.push_back(Napi::ThreadSafeFunction::New(
		env, fn, "Ireina saikou!!", 0, 1,
		[] (Napi::Env) { }
	));
}
void RenderCallbacks::registerWindowEventCallback(Napi::Env env, const Napi::Function& fn) {
	windowEventCallbackList.push_back(Napi::ThreadSafeFunction::New(
		env, fn, "Kotori saikou!!", 0, 1,
		[] (Napi::Env) { }
	));
}

void Render::SetColor(const KColor* color) {
	SDL_SetRenderDrawColor(gRenderer, color->r, color->g, color->b, color->a);
}

void Render::DrawLine(const KPoint* st, const KPoint* ed) {
	SDL_RenderDrawLine(gRenderer, st->x, st->y, ed->x, ed->y);
}

void Render::DrawPoint(const KPoint* p) {
	SDL_RenderDrawPoint(gRenderer, p->x, p->y);
}

void Render::DrawRect(const KRect* r) {
	SDL_RenderDrawRect(gRenderer, r);
}
void Render::FillRect(const KRect* r) {
	SDL_RenderFillRect(gRenderer, r);
}
void Render::DrawImage(const int& tid, const KRect* srcrect, const KRect* dstrect) {
	auto res = textureMap.find(tid);
	if (res == textureMap.end()) {
		return;
	}
	SDL_RenderCopy(gRenderer, res -> second, srcrect, dstrect);
}

void Render::RenderPresent() {
	SDL_RenderPresent(gRenderer);
}

KTexture* Render::registerTexture(std::string src) {
	SDL_Surface* surface = IMG_Load(src.c_str());
	if (surface == NULL) {
		return NULL;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
	KTexture* kt = addTexture(texture, surface->w, surface->h);
	SDL_FreeSurface(surface);
	return kt;
}
KFont* Render::registerFont(std::string src, int size) {
	TTF_Font* font = TTF_OpenFont(src.c_str(), size);
	if (font == NULL) {
		return NULL;
	}
	return addFont(font, size);
}
KTexture* Render::renderText(const int& fid, std::string text, KColor* color) {
	auto font = fontMap.find(fid);
	if (font == fontMap.end()) {
		return NULL;
	}
	// TODO more render options
	SDL_Surface* surface = TTF_RenderUTF8_Blended(font->second, text.c_str(), *color);
	if (surface == NULL) {
		return NULL;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(gRenderer, surface);
	if (texture == NULL) {
		return NULL;
	}
	KTexture* kt = addTexture(texture, surface->w, surface->h);
	SDL_FreeSurface(surface);
	return kt;
}

bool Render::init(const char *title, int x, int y, int w, int h, Uint32 flags) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	gWindow = SDL_CreateWindow(title, x, y, w, h, flags);
	if (gWindow == NULL) {
		return false;
	}
	// anti alias
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL) {
		return false;
	}

	const int imgflag = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
	if ((IMG_Init(imgflag) & imgflag) != imgflag) {
		return false;
	}

	if (TTF_Init() == -1) {
		return false;
	}

	return true;
}

bool quit = false;
void Render::quit() {
	::quit = true;
}

void Render::close() {
	for (auto &pr : textureMap) {
		SDL_DestroyTexture(pr.second);
		pr.second = NULL;
	}
	for (auto &pr : fontMap) {
		TTF_CloseFont(pr.second);
		pr.second = NULL;
	}

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Render::eventLoop() {
	::quit = false;
	SDL_Event e;
	while (!::quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT || e.type == SDL_WINDOWEVENT) {
				for (auto& tsfn : windowEventCallbackList) {
					tsfn.BlockingCall(new SDL_Event(e), windowEventCallback);
				}
			}
			if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) {
				for (auto& tsfn : keyEventCallbackList) {
					tsfn.BlockingCall(new SDL_Event(e), keyEventCallback);
				}
			}
			if (e.type == SDL_MOUSEMOTION ||
					e.type == SDL_MOUSEWHEEL ||
					e.type == SDL_MOUSEBUTTONUP ||
					e.type == SDL_MOUSEBUTTONDOWN) {
				for (auto& tsfn : mouseEventCallbackList) {
					tsfn.BlockingCall(new SDL_Event(e), mouseEventCallback);
				}
			}
		}
	}
}
