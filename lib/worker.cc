#include "worker.h"

Napi::ThreadSafeFunction tsfn = NULL;

void tsfnCallback(Napi::Env env, Napi::Function fn, bool* e) {
  Napi::Value success = Napi::Boolean::New(env, *e);
	fn.Call({ success });
	delete e;
}

RenderWorker::RenderWorker(Napi::Function& callback)
  : Napi::AsyncWorker(callback) {}

RenderWorker::~RenderWorker() {}

void RenderWorker::Execute() {
  bool success = Render::init();
  tsfn.BlockingCall(new bool(success), tsfnCallback);
  Render::eventLoop();
}

void RenderWorker::OnOK() {
  Callback().Call({Env().Undefined()});
}

Napi::Value None(const Napi::CallbackInfo& info) {
  return info.Env().Undefined();
}

Napi::Value StartEventLoop(const Napi::CallbackInfo& info) {
  Napi::Function callback1, callback2;
  if (info.Length() > 0 && info[0].IsFunction()) {
    callback1 = info[0].As<Napi::Function>();
  } else {
    callback1 = Napi::Function::New(info.Env(), None);
  }
  if (info.Length() > 1 && info[1].IsFunction()) {
    callback2 = info[1].As<Napi::Function>();
  } else {
    callback2 = Napi::Function::New(info.Env(), None);
  }
  tsfn = Napi::ThreadSafeFunction::New(info.Env(), callback1, "Elaina is my waifu!!", 0, 1, [] (Napi::Env) { });
  RenderWorker* piWorker = new RenderWorker(callback2);
  piWorker->Queue();
  return info.Env().Undefined();
}
