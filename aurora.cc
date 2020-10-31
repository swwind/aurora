#include <napi.h>
#include "lib/render.h"
#include "lib/worker.h"

Napi::Value BindKeyEventCallback(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Function fn = info[0].As<Napi::Function>();
	RenderCallbacks::registerKeyEventCallback(env, fn);
	return env.Undefined();
}
Napi::Value BindMouseEventCallback(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Function fn = info[0].As<Napi::Function>();
	RenderCallbacks::registerMouseEventCallback(env, fn);
	return env.Undefined();
}
Napi::Value BindWindowEventCallback(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Function fn = info[0].As<Napi::Function>();
	RenderCallbacks::registerWindowEventCallback(env, fn);
	return env.Undefined();
}

Napi::Value DrawLine(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	KPoint* st = parsePoint(info[0]);
	KPoint* ed = parsePoint(info[1]);
	KColor* color = parseColor(info[2]);

	Render::SetColor(color);
	Render::DrawLine(st, ed);

	delete color;
	delete st;
	delete ed;
	return env.Undefined();
}
Napi::Value DrawPoint(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	KPoint* point = parsePoint(info[0]);
	KColor* color = parseColor(info[1]);

	Render::SetColor(color);
	Render::DrawPoint(point);

	delete color;
	delete point;
	return env.Undefined();
}
Napi::Value DrawRect(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	KRect* rect = parseRect(info[0]);
	KColor* color = parseColor(info[1]);

	Render::SetColor(color);
	Render::DrawRect(rect);

	delete color;
	delete rect;
	return env.Undefined();
}
Napi::Value FillRect(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	KRect* rect = parseRect(info[0]);
	KColor* color = parseColor(info[1]);

	Render::SetColor(color);
	Render::FillRect(rect);

	delete color;
	delete rect;
	return env.Undefined();
}
Napi::Value DrawImage(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int tid = info[0].As<Napi::Number>().Int32Value();
	KRect* dstrect = parseRect(info[1]);
	KRect* srcrect = parseRect(info[2]);

	Render::DrawImage(tid, srcrect, dstrect);

	delete srcrect;
	delete dstrect;
	return env.Undefined();
}

Napi::Value RenderPresent(const Napi::CallbackInfo& info) {
	Render::RenderPresent();
	return info.Env().Undefined();
}

#define CheckConfig(a, b, c) \
	if (config.Has(a) && config.Get(a).As<Napi::Boolean>().Value() != c) { \
		flag ^= SDL_WINDOW_ ## b; \
	}

Napi::Value RenderInit(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	std::string title = config.Get("title").As<Napi::String>();
	int w = config.Get("w").As<Napi::Number>().Int32Value();
	int h = config.Get("h").As<Napi::Number>().Int32Value();
	int x = SDL_WINDOWPOS_CENTERED, y = SDL_WINDOWPOS_CENTERED;
	Napi::Value xx = config.Get("x");
	if (xx.IsNumber()) { x = xx.As<Napi::Number>().Int32Value(); }
	Napi::Value yy = config.Get("y");
	if (yy.IsNumber()) { y = yy.As<Napi::Number>().Int32Value(); }

	int flag = SDL_WINDOW_SHOWN;
	CheckConfig("fullscreen", FULLSCREEN, false);
	CheckConfig("opengl", OPENGL, false);
	CheckConfig("shown", SHOWN, true);
	CheckConfig("hidden", HIDDEN, false);
	CheckConfig("borderless", BORDERLESS, false);
	CheckConfig("resizable", RESIZABLE, false);
	CheckConfig("minimized", MINIMIZED, false);
	CheckConfig("maximized", MAXIMIZED, false);
	CheckConfig("input_grabbed", INPUT_GRABBED, false);
	CheckConfig("input_focus", INPUT_FOCUS, false);
	CheckConfig("mouse_focus", MOUSE_FOCUS, false);
	CheckConfig("fullscreen_desktop", FULLSCREEN_DESKTOP, false);
	CheckConfig("foreign", FOREIGN, false);
	CheckConfig("allow_highdpi", ALLOW_HIGHDPI, false);
	CheckConfig("mouse_capture", MOUSE_CAPTURE, false);
	CheckConfig("always_on_top", ALWAYS_ON_TOP, false);
	CheckConfig("skip_taskbar", SKIP_TASKBAR, false);
	CheckConfig("utility", UTILITY, false);
	CheckConfig("tooltip", TOOLTIP, false);
	CheckConfig("popup_menu", POPUP_MENU, false);
	CheckConfig("vulkan", VULKAN, false);

	bool success = Render::init(title.c_str(), x, y, w, h, flag);
	return Napi::Boolean::New(env, success);
}
Napi::Value RenderQuit(const Napi::CallbackInfo& info) {
	Render::quit();
	return info.Env().Undefined();
}
Napi::Value RenderClose(const Napi::CallbackInfo& info) {
	Render::close();
	return info.Env().Undefined();
}

Napi::Value RegisterTexture(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	std::string src = info[0].As<Napi::String>();
	KTexture* texture = Render::registerTexture(src);
	Napi::Object ret = Napi::Object::New(env);
	ret["id"] = texture->id;
	ret["width"] = texture->width;
	ret["height"] = texture->height;
	delete texture;
	return ret;
}
Napi::Value RegisterFont(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	std::string src = info[0].As<Napi::String>();
	int size = info[1].As<Napi::Number>().Int32Value();
	KFont* font = Render::registerFont(src, size);
	Napi::Object ret = Napi::Object::New(env);
	ret["id"] = font->id;
	ret["size"] = font->size;
	delete font;
	return ret;
}
Napi::Value RegisterMusic(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	std::string src = info[0].As<Napi::String>();
	KMusic* music = Render::registerMusic(src);
	Napi::Object ret = Napi::Object::New(env);
	ret["id"] = music->id;
	delete music;
	return ret;
}
Napi::Value RegisterSound(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	std::string src = info[0].As<Napi::String>();
	KSound* sound = Render::registerSound(src);
	Napi::Object ret = Napi::Object::New(env);
	ret["id"] = sound->id;
	delete sound;
	return ret;
}
Napi::Value RenderText(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int fid = info[0].As<Napi::Number>().Int32Value();
	std::string text = info[1].As<Napi::String>();
	KColor* color = parseColor(info[2]);
	KTexture* texture = Render::renderText(fid, text, color);
	Napi::Object ret = Napi::Object::New(env);
	ret["id"] = texture->id;
	ret["width"] = texture->width;
	ret["height"] = texture->height;
	delete color;
	delete texture;
	return ret;
}

Napi::Value PlayMusic(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int mid = info[0].As<Napi::Number>().Int32Value();
	int loops = info[1].As<Napi::Number>().Int32Value();
	Render::playMusic(mid, loops);
	return env.Undefined();
}
Napi::Value PauseMusic(const Napi::CallbackInfo& info) {
	Render::pauseMusic();
	return info.Env().Undefined();
}
Napi::Value ResumeMusic(const Napi::CallbackInfo& info) {
	Render::resumeMusic();
	return info.Env().Undefined();
}
Napi::Value ToggleMusic(const Napi::CallbackInfo& info) {
	Render::toggleMusic();
	return info.Env().Undefined();
}
Napi::Value PlaySound(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int sid = info[0].As<Napi::Number>().Int32Value();
	int channel = info[1].As<Napi::Number>().Int32Value();
	int loops = info[2].As<Napi::Number>().Int32Value();
	Render::playSound(sid, channel, loops);
	return env.Undefined();
}

Napi::Value DeleteTexture(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int texture_id = info[0].As<Napi::Number>().Int32Value();
	Render::deleteTexture(texture_id);
	return env.Undefined();
}
Napi::Value DeleteFont(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int font_id = info[0].As<Napi::Number>().Int32Value();
	Render::deleteFont(font_id);
	return env.Undefined();
}
Napi::Value DeleteMusic(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int music_id = info[0].As<Napi::Number>().Int32Value();
	Render::deleteMusic(music_id);
	return env.Undefined();
}
Napi::Value DeleteSound(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	int sound_id = info[0].As<Napi::Number>().Int32Value();
	Render::deleteSound(sound_id);
	return env.Undefined();
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	// events
	exports["startEventLoop"] = Napi::Function::New(env, StartEventLoop);
	exports["bindKeyEventCallback"] = Napi::Function::New(env, BindKeyEventCallback);
	exports["bindMouseEventCallback"] = Napi::Function::New(env, BindMouseEventCallback);
	exports["bindWindowEventCallback"] = Napi::Function::New(env, BindWindowEventCallback);

	// drawing
	exports["drawLine"] = Napi::Function::New(env, DrawLine);
	exports["drawPoint"] = Napi::Function::New(env, DrawPoint);
	exports["drawRect"] = Napi::Function::New(env, DrawRect);
	exports["fillRect"] = Napi::Function::New(env, FillRect);
	exports["drawImage"] = Napi::Function::New(env, DrawImage);

	// render
	exports["init"] = Napi::Function::New(env, RenderInit);
	exports["quit"] = Napi::Function::New(env, RenderQuit);
	exports["render"] = Napi::Function::New(env, RenderPresent);
	exports["close"] = Napi::Function::New(env, RenderClose);

	// sources
	exports["registerTexture"] = Napi::Function::New(env, RegisterTexture);
	exports["registerFont"] = Napi::Function::New(env, RegisterFont);
	exports["registerMusic"] = Napi::Function::New(env, RegisterMusic);
	exports["registerSound"] = Napi::Function::New(env, RegisterSound);
	exports["renderText"] = Napi::Function::New(env, RenderText);
	exports["deleteTexture"] = Napi::Function::New(env, DeleteTexture);
	exports["deleteFont"] = Napi::Function::New(env, DeleteFont);
	exports["deleteMusic"] = Napi::Function::New(env, DeleteMusic);
	exports["deleteSound"] = Napi::Function::New(env, DeleteSound);

	// sounds
	exports["playMusic"] = Napi::Function::New(env, PlayMusic);
	exports["pauseMusic"] = Napi::Function::New(env, PauseMusic);
	exports["resumeMusic"] = Napi::Function::New(env, ResumeMusic);
	exports["toggleMusic"] = Napi::Function::New(env, ToggleMusic);
	exports["playSound"] = Napi::Function::New(env, PlaySound);
  return exports;
}

NODE_API_MODULE(katolide, Init);
