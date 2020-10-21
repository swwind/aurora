#ifndef WORKER_H
#define WORKER_H

#include "napi.h"
#include "render.h"

class RenderWorker : public Napi::AsyncWorker {
 public:
  RenderWorker(Napi::Function& callback);
  ~RenderWorker();

  void Execute();

  void OnOK();
};

Napi::Value StartEventLoop(const Napi::CallbackInfo& info);

#endif // WORKER_H
