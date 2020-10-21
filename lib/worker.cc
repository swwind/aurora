#include "worker.h"

RenderWorker::RenderWorker(Napi::Function& callback)
  : Napi::AsyncWorker(callback) {}

RenderWorker::~RenderWorker() {}

void RenderWorker::Execute() {
  Render::eventLoop();
  Render::close();
}

void RenderWorker::OnOK() {
  Callback().Call({Env().Undefined()});
}

Napi::Value StartEventLoop(const Napi::CallbackInfo& info) {
  Napi::Function callback = info[0].As<Napi::Function>();
  RenderWorker* piWorker = new RenderWorker(callback);
  piWorker->Queue();
  return info.Env().Undefined();
}
