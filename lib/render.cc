#include "render.h"

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

std::map<int, SDL_Texture*> textureMap;

std::vector<Napi::ThreadSafeFunction>
	keyEventCallbackList,
	mouseEventCallbackList,
	windowEventCallbackList;

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

SDL_Texture* loadTexture(std::string path) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		return NULL;
	}
	newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	return newTexture;
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

int cnt = 0;
int Render::registerTexture(std::string src) {
  SDL_Texture* texture = loadTexture(src);
  if (texture == NULL) {
    return false;
  }
	int id = ++ cnt;
  textureMap.insert(std::make_pair(cnt, texture));
  return id;
}

bool Render::init(const char *title, int x, int y, int w, int h, Uint32 flags) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	gWindow = SDL_CreateWindow(title, x, y, w, h, flags);
	if (gWindow == NULL) {
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL) {
		return false;
	}

	const int imgflag = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
	if((IMG_Init(imgflag) & imgflag) != imgflag) {
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

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

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
