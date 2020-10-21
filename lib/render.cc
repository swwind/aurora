#include "render.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

std::map<int, SDL_Texture*> textureMap;

std::vector<Napi::ThreadSafeFunction>
	keyEventCallbackList,
	mouseEventCallbackList;

void keyEventCallback(Napi::Env env, Napi::Function fn, SDL_Event* e) {
	Napi::Object result = Napi::Object::New(env);
	result["type"] = getEventType(e->type);
	result["keycode"] = e->key.keysym.sym;
	result["key"] = getKeyCode(e->key.keysym.sym);

	fn.Call({ result });
	delete e;
}
void mouseEventCallback(Napi::Env env, Napi::Function fn, SDL_Event* e) {
	int x, y;
	SDL_GetMouseState(&x, &y);

	Napi::Object result = Napi::Object::New(env);
	result["type"] = getEventType(e->type);
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

void Render::SetColor(const KColor& color) {
	SDL_SetRenderDrawColor(gRenderer, color.r, color.g, color.b, color.a);
}

void Render::DrawLine(const KPoint& st, const KPoint& ed) {
	SDL_RenderDrawLine(gRenderer, st.x, st.y, ed.x, ed.y);
}

void Render::DrawPoint(const KPoint& p) {
	SDL_RenderDrawPoint(gRenderer, p.x, p.y);
}

void Render::DrawRect(const KRect& r) {
	SDL_RenderDrawRect(gRenderer, &r);
}
void Render::FillRect(const KRect& r) {
	SDL_RenderFillRect(gRenderer, &r);
}

void Render::RenderPresent() {
	SDL_RenderPresent(gRenderer);
}

bool Render::registerTexture(int id, std::string src) {
  SDL_Texture* texture = loadTexture(src);
  if (texture == NULL) {
    return false;
  }
  textureMap.insert(std::make_pair(id, texture));
  return true;
}

bool Render::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL) {
		return false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL) {
		return false;
	}

	const int imgflag = IMG_INIT_PNG;
	if((IMG_Init(imgflag) & imgflag) != imgflag) {
		return false;
	}

	return true;
}

void Render::close() {
	for (auto &pr : textureMap) {
		SDL_DestroyTexture(pr.second);
		pr.second = NULL;
	}

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Render::eventLoop() {
	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if( e.type == SDL_QUIT ) {
				quit = true;
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
