#ifndef KEYS_H
#define KEYS_H

#include <SDL2/SDL.h>
#include "napi.h"

std::string getKeyCode(uint32_t x);
std::string getEventType(uint32_t type);
std::string getMouseType(uint8_t type);

#endif // KEYS_H
