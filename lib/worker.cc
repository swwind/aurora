#include "render.cc"

class RenderWorker : public Napi::AsyncWorker {
 public:
  RenderWorker(Napi::Function& callback)
      : Napi::AsyncWorker(callback) {}
  ~RenderWorker() {}

  void Execute() {
    Render::eventLoop();
		Render::close();
  }

  void OnOK() {
    Callback().Call({Env().Undefined()});
  }
};

Napi::Value StartEventLoop(const Napi::CallbackInfo& info) {
  Napi::Function callback = info[0].As<Napi::Function>();
  RenderWorker* piWorker = new RenderWorker(callback);
  piWorker->Queue();
  return info.Env().Undefined();
}
