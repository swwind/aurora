#ifndef KEYS_H
#define KEYS_H

#include <SDL2/SDL.h>
#include "napi.h"

Napi::String SDL_KeyCode_to_string(const Napi::Env& env, SDL_KeyCode x);

#endif // KEYS_H
