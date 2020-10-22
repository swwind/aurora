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
	Napi::Object config = info[0].As<Napi::Object>();
	KColor* color = parseColor(config.Get("color"));
	KPoint* st = parsePoint(config.Get("start"));
	KPoint* ed = parsePoint(config.Get("end"));

	Render::SetColor(color);
	Render::DrawLine(st, ed);

	delete color;
	delete st;
	delete ed;
	return env.Undefined();
}
Napi::Value DrawPoint(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	KColor* color = parseColor(config.Get("color"));
	KPoint* point = parsePoint(config.Get("point"));

	Render::SetColor(color);
	Render::DrawPoint(point);

	delete color;
	delete point;
	return env.Undefined();
}
Napi::Value DrawRect(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	KColor* color = parseColor(config.Get("color"));
	KRect* rect = parseRect(config.Get("rect"));

	Render::SetColor(color);
	Render::DrawRect(rect);

	delete color;
	delete rect;
	return env.Undefined();
}
Napi::Value FillRect(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	KColor* color = parseColor(config.Get("color"));
	KRect* rect = parseRect(config.Get("rect"));

	Render::SetColor(color);
	Render::FillRect(rect);

	delete color;
	delete rect;
	return env.Undefined();
}
Napi::Value DrawImage(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	int texture = config.Get("texture").As<Napi::Number>().Int32Value();
	KRect* srcrect = parseRect(config.Get("srcrect"));
	KRect* dstrect = parseRect(config.Get("dstrect"));

	Render::DrawImage(texture, srcrect, dstrect);

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
		flag ^= SDL_WINDOW_ ## b;\
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
	int tid = Render::registerTexture(src);
	return Napi::Number::New(env, tid);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports["startEventLoop"] = Napi::Function::New(env, StartEventLoop);
	exports["bindKeyEventCallback"] = Napi::Function::New(env, BindKeyEventCallback);
	exports["bindMouseEventCallback"] = Napi::Function::New(env, BindMouseEventCallback);
	exports["bindWindowEventCallback"] = Napi::Function::New(env, BindWindowEventCallback);

	// geometry
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
  return exports;
}

NODE_API_MODULE(katolide, Init);
