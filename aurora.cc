#include <napi.h>
#include "lib/worker.cc"

Napi::Value BindKeyEventCallback(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Function fn = info[0].As<Napi::Function>();
	keyEventCallbackList.push_back(Napi::ThreadSafeFunction::New(
		env,
		fn,
		"Emilia saikou!!",
		0, 1,
		[](Napi::Env) { }
	));
	return env.Undefined();
}

Napi::Value DrawLine(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	KColor color = parseColor(&env, config.Get("color"));
	KPoint st = parsePoint(&env, config.Get("start"));
	KPoint ed = parsePoint(&env, config.Get("end"));

	Render::SetColor(color);
	Render::DrawLine(st, ed);

	return env.Undefined();
}
Napi::Value DrawPoint(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	KColor color = parseColor(&env, config.Get("color"));
	KPoint point = parsePoint(&env, config.Get("point"));

	Render::SetColor(color);
	Render::DrawPoint(point);

	return env.Undefined();
}
Napi::Value DrawRect(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	KColor color = parseColor(&env, config.Get("color"));
	KRect rect = parseRect(&env, config.Get("rect"));

	Render::SetColor(color);
	Render::DrawRect(rect);

	return env.Undefined();
}
Napi::Value FillRect(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	Napi::Object config = info[0].As<Napi::Object>();
	KColor color = parseColor(&env, config.Get("color"));
	KRect rect = parseRect(&env, config.Get("rect"));

	Render::SetColor(color);
	Render::FillRect(rect);

	return env.Undefined();
}

Napi::Value RenderPresent(const Napi::CallbackInfo& info) {
	Render::RenderPresent();
	return info.Env().Undefined();
}
Napi::Value RenderInit(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();
	bool success = Render::init();
	return Napi::Boolean::New(env, success);
}


Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports["startEventLoop"] = Napi::Function::New(env, StartEventLoop);
	exports["bindKeyEventCallback"] = Napi::Function::New(env, BindKeyEventCallback);

	// geometry
	exports["drawLine"] = Napi::Function::New(env, DrawLine);
	exports["drawPoint"] = Napi::Function::New(env, DrawPoint);
	exports["drawRect"] = Napi::Function::New(env, DrawRect);
	exports["fillRect"] = Napi::Function::New(env, FillRect);

	// render
	exports["init"] = Napi::Function::New(env, RenderInit);
	exports["render"] = Napi::Function::New(env, RenderPresent);
  return exports;
}

NODE_API_MODULE(katolide, Init)
