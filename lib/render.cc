#include "render.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

std::map<int, SDL_Texture*> textureMap;

std::vector<Napi::ThreadSafeFunction> keyEventCallbackList;

void RenderCallbacks::keyDownEventCallback(Napi::Env env, Napi::Function fn, int* e) {
	Napi::Object result = Napi::Object::New(env);
	result.Set(Napi::String::New(env, "type"),
		Napi::String::New(env, "keydown"));
	result.Set(Napi::String::New(env, "keycode"),
		Napi::Number::New(env, *e));
	result.Set(Napi::String::New(env, "key"),
		SDL_KeyCode_to_string(env, (SDL_KeyCode) *e));

	fn.Call({ result });
	delete e;
}
void RenderCallbacks::keyUpEventCallback(Napi::Env env, Napi::Function fn, int* e) {
	Napi::Object result = Napi::Object::New(env);
	result.Set(Napi::String::New(env, "type"),
		Napi::String::New(env, "keyup"));
	result.Set(Napi::String::New(env, "keycode"),
		Napi::Number::New(env, *e));
	result.Set(Napi::String::New(env, "key"),
		SDL_KeyCode_to_string(env, (SDL_KeyCode) *e));

	fn.Call({ result });
	delete e;
}
void RenderCallbacks::registerKeyEventCallback(Napi::Env env, const Napi::Function& fn) {
	keyEventCallbackList.push_back(Napi::ThreadSafeFunction::New(
		env, fn, "Emilia saikou!!", 0, 1,
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
			if (e.type == SDL_KEYDOWN) {
				for (auto tsfn = keyEventCallbackList.begin(); tsfn != keyEventCallbackList.end(); ++ tsfn) {
					tsfn -> BlockingCall(new int(e.key.keysym.sym), RenderCallbacks::keyDownEventCallback);
				}
			}
			if (e.type == SDL_KEYUP) {
				for (auto tsfn = keyEventCallbackList.begin(); tsfn != keyEventCallbackList.end(); ++ tsfn) {
					tsfn -> BlockingCall(new int(e.key.keysym.sym), RenderCallbacks::keyUpEventCallback);
				}
			}
		}
	}
}
