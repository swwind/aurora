#include "worker.h"

RenderWorker::RenderWorker(Napi::Function& callback)
  : Napi::AsyncWorker(callback) {}

RenderWorker::~RenderWorker() {}

void RenderWorker::Execute() {
  Render::eventLoop();
}

void RenderWorker::OnOK() {
  Callback().Call({Env().Undefined()});
}

Napi::Value None(const Napi::CallbackInfo& info) {
  return info.Env().Undefined();
}

Napi::Value StartEventLoop(const Napi::CallbackInfo& info) {
  Napi::Function callback;
  if (info.Length() > 0 && info[0].IsFunction()) {
    callback = info[0].As<Napi::Function>();
  } else {
    callback = Napi::Function::New(info.Env(), None);
  }
  RenderWorker* piWorker = new RenderWorker(callback);
  piWorker->Queue();
  return info.Env().Undefined();
}
