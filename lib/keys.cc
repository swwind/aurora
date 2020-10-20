#include <SDL2/SDL.h>
#include "napi.h"

Napi::String SDL_KeyCode_to_string(Napi::Env& env, SDL_KeyCode x) {
  switch (x) {
    case SDLK_UNKNOWN: return Napi::String::New(env, "UNKNOWN");
    case SDLK_RETURN: return Napi::String::New(env, "RETURN");
    case SDLK_ESCAPE: return Napi::String::New(env, "ESCAPE");
    case SDLK_BACKSPACE: return Napi::String::New(env, "BACKSPACE");
    case SDLK_TAB: return Napi::String::New(env, "TAB");
    case SDLK_SPACE: return Napi::String::New(env, "SPACE");
    case SDLK_EXCLAIM: return Napi::String::New(env, "EXCLAIM");
    case SDLK_QUOTEDBL: return Napi::String::New(env, "QUOTEDBL");
    case SDLK_HASH: return Napi::String::New(env, "HASH");
    case SDLK_PERCENT: return Napi::String::New(env, "PERCENT");
    case SDLK_DOLLAR: return Napi::String::New(env, "DOLLAR");
    case SDLK_AMPERSAND: return Napi::String::New(env, "AMPERSAND");
    case SDLK_QUOTE: return Napi::String::New(env, "QUOTE");
    case SDLK_LEFTPAREN: return Napi::String::New(env, "LEFTPAREN");
    case SDLK_RIGHTPAREN: return Napi::String::New(env, "RIGHTPAREN");
    case SDLK_ASTERISK: return Napi::String::New(env, "ASTERISK");
    case SDLK_PLUS: return Napi::String::New(env, "PLUS");
    case SDLK_COMMA: return Napi::String::New(env, "COMMA");
    case SDLK_MINUS: return Napi::String::New(env, "MINUS");
    case SDLK_PERIOD: return Napi::String::New(env, "PERIOD");
    case SDLK_SLASH: return Napi::String::New(env, "SLASH");
    case SDLK_0: return Napi::String::New(env, "0");
    case SDLK_1: return Napi::String::New(env, "1");
    case SDLK_2: return Napi::String::New(env, "2");
    case SDLK_3: return Napi::String::New(env, "3");
    case SDLK_4: return Napi::String::New(env, "4");
    case SDLK_5: return Napi::String::New(env, "5");
    case SDLK_6: return Napi::String::New(env, "6");
    case SDLK_7: return Napi::String::New(env, "7");
    case SDLK_8: return Napi::String::New(env, "8");
    case SDLK_9: return Napi::String::New(env, "9");
    case SDLK_COLON: return Napi::String::New(env, "COLON");
    case SDLK_SEMICOLON: return Napi::String::New(env, "SEMICOLON");
    case SDLK_LESS: return Napi::String::New(env, "LESS");
    case SDLK_EQUALS: return Napi::String::New(env, "EQUALS");
    case SDLK_GREATER: return Napi::String::New(env, "GREATER");
    case SDLK_QUESTION: return Napi::String::New(env, "QUESTION");
    case SDLK_AT: return Napi::String::New(env, "AT");
    case SDLK_LEFTBRACKET: return Napi::String::New(env, "LEFTBRACKET");
    case SDLK_BACKSLASH: return Napi::String::New(env, "BACKSLASH");
    case SDLK_RIGHTBRACKET: return Napi::String::New(env, "RIGHTBRACKET");
    case SDLK_CARET: return Napi::String::New(env, "CARET");
    case SDLK_UNDERSCORE: return Napi::String::New(env, "UNDERSCORE");
    case SDLK_BACKQUOTE: return Napi::String::New(env, "BACKQUOTE");
    case SDLK_a: return Napi::String::New(env, "a");
    case SDLK_b: return Napi::String::New(env, "b");
    case SDLK_c: return Napi::String::New(env, "c");
    case SDLK_d: return Napi::String::New(env, "d");
    case SDLK_e: return Napi::String::New(env, "e");
    case SDLK_f: return Napi::String::New(env, "f");
    case SDLK_g: return Napi::String::New(env, "g");
    case SDLK_h: return Napi::String::New(env, "h");
    case SDLK_i: return Napi::String::New(env, "i");
    case SDLK_j: return Napi::String::New(env, "j");
    case SDLK_k: return Napi::String::New(env, "k");
    case SDLK_l: return Napi::String::New(env, "l");
    case SDLK_m: return Napi::String::New(env, "m");
    case SDLK_n: return Napi::String::New(env, "n");
    case SDLK_o: return Napi::String::New(env, "o");
    case SDLK_p: return Napi::String::New(env, "p");
    case SDLK_q: return Napi::String::New(env, "q");
    case SDLK_r: return Napi::String::New(env, "r");
    case SDLK_s: return Napi::String::New(env, "s");
    case SDLK_t: return Napi::String::New(env, "t");
    case SDLK_u: return Napi::String::New(env, "u");
    case SDLK_v: return Napi::String::New(env, "v");
    case SDLK_w: return Napi::String::New(env, "w");
    case SDLK_x: return Napi::String::New(env, "x");
    case SDLK_y: return Napi::String::New(env, "y");
    case SDLK_z: return Napi::String::New(env, "z");
    case SDLK_CAPSLOCK: return Napi::String::New(env, "CAPSLOCK");
    case SDLK_F1: return Napi::String::New(env, "F1");
    case SDLK_F2: return Napi::String::New(env, "F2");
    case SDLK_F3: return Napi::String::New(env, "F3");
    case SDLK_F4: return Napi::String::New(env, "F4");
    case SDLK_F5: return Napi::String::New(env, "F5");
    case SDLK_F6: return Napi::String::New(env, "F6");
    case SDLK_F7: return Napi::String::New(env, "F7");
    case SDLK_F8: return Napi::String::New(env, "F8");
    case SDLK_F9: return Napi::String::New(env, "F9");
    case SDLK_F10: return Napi::String::New(env, "F10");
    case SDLK_F11: return Napi::String::New(env, "F11");
    case SDLK_F12: return Napi::String::New(env, "F12");
    case SDLK_PRINTSCREEN: return Napi::String::New(env, "PRINTSCREEN");
    case SDLK_SCROLLLOCK: return Napi::String::New(env, "SCROLLLOCK");
    case SDLK_PAUSE: return Napi::String::New(env, "PAUSE");
    case SDLK_INSERT: return Napi::String::New(env, "INSERT");
    case SDLK_HOME: return Napi::String::New(env, "HOME");
    case SDLK_PAGEUP: return Napi::String::New(env, "PAGEUP");
    case SDLK_DELETE: return Napi::String::New(env, "DELETE");
    case SDLK_END: return Napi::String::New(env, "END");
    case SDLK_PAGEDOWN: return Napi::String::New(env, "PAGEDOWN");
    case SDLK_RIGHT: return Napi::String::New(env, "RIGHT");
    case SDLK_LEFT: return Napi::String::New(env, "LEFT");
    case SDLK_DOWN: return Napi::String::New(env, "DOWN");
    case SDLK_UP: return Napi::String::New(env, "UP");
    case SDLK_NUMLOCKCLEAR: return Napi::String::New(env, "NUMLOCKCLEAR");
    case SDLK_KP_DIVIDE: return Napi::String::New(env, "KP_DIVIDE");
    case SDLK_KP_MULTIPLY: return Napi::String::New(env, "KP_MULTIPLY");
    case SDLK_KP_MINUS: return Napi::String::New(env, "KP_MINUS");
    case SDLK_KP_PLUS: return Napi::String::New(env, "KP_PLUS");
    case SDLK_KP_ENTER: return Napi::String::New(env, "KP_ENTER");
    case SDLK_KP_1: return Napi::String::New(env, "KP_1");
    case SDLK_KP_2: return Napi::String::New(env, "KP_2");
    case SDLK_KP_3: return Napi::String::New(env, "KP_3");
    case SDLK_KP_4: return Napi::String::New(env, "KP_4");
    case SDLK_KP_5: return Napi::String::New(env, "KP_5");
    case SDLK_KP_6: return Napi::String::New(env, "KP_6");
    case SDLK_KP_7: return Napi::String::New(env, "KP_7");
    case SDLK_KP_8: return Napi::String::New(env, "KP_8");
    case SDLK_KP_9: return Napi::String::New(env, "KP_9");
    case SDLK_KP_0: return Napi::String::New(env, "KP_0");
    case SDLK_KP_PERIOD: return Napi::String::New(env, "KP_PERIOD");
    case SDLK_APPLICATION: return Napi::String::New(env, "APPLICATION");
    case SDLK_POWER: return Napi::String::New(env, "POWER");
    case SDLK_KP_EQUALS: return Napi::String::New(env, "KP_EQUALS");
    case SDLK_F13: return Napi::String::New(env, "F13");
    case SDLK_F14: return Napi::String::New(env, "F14");
    case SDLK_F15: return Napi::String::New(env, "F15");
    case SDLK_F16: return Napi::String::New(env, "F16");
    case SDLK_F17: return Napi::String::New(env, "F17");
    case SDLK_F18: return Napi::String::New(env, "F18");
    case SDLK_F19: return Napi::String::New(env, "F19");
    case SDLK_F20: return Napi::String::New(env, "F20");
    case SDLK_F21: return Napi::String::New(env, "F21");
    case SDLK_F22: return Napi::String::New(env, "F22");
    case SDLK_F23: return Napi::String::New(env, "F23");
    case SDLK_F24: return Napi::String::New(env, "F24");
    case SDLK_EXECUTE: return Napi::String::New(env, "EXECUTE");
    case SDLK_HELP: return Napi::String::New(env, "HELP");
    case SDLK_MENU: return Napi::String::New(env, "MENU");
    case SDLK_SELECT: return Napi::String::New(env, "SELECT");
    case SDLK_STOP: return Napi::String::New(env, "STOP");
    case SDLK_AGAIN: return Napi::String::New(env, "AGAIN");
    case SDLK_UNDO: return Napi::String::New(env, "UNDO");
    case SDLK_CUT: return Napi::String::New(env, "CUT");
    case SDLK_COPY: return Napi::String::New(env, "COPY");
    case SDLK_PASTE: return Napi::String::New(env, "PASTE");
    case SDLK_FIND: return Napi::String::New(env, "FIND");
    case SDLK_MUTE: return Napi::String::New(env, "MUTE");
    case SDLK_VOLUMEUP: return Napi::String::New(env, "VOLUMEUP");
    case SDLK_VOLUMEDOWN: return Napi::String::New(env, "VOLUMEDOWN");
    case SDLK_KP_COMMA: return Napi::String::New(env, "KP_COMMA");
    case SDLK_KP_EQUALSAS400: return Napi::String::New(env, "KP_EQUALSAS400");
    case SDLK_ALTERASE: return Napi::String::New(env, "ALTERASE");
    case SDLK_SYSREQ: return Napi::String::New(env, "SYSREQ");
    case SDLK_CANCEL: return Napi::String::New(env, "CANCEL");
    case SDLK_CLEAR: return Napi::String::New(env, "CLEAR");
    case SDLK_PRIOR: return Napi::String::New(env, "PRIOR");
    case SDLK_RETURN2: return Napi::String::New(env, "RETURN2");
    case SDLK_SEPARATOR: return Napi::String::New(env, "SEPARATOR");
    case SDLK_OUT: return Napi::String::New(env, "OUT");
    case SDLK_OPER: return Napi::String::New(env, "OPER");
    case SDLK_CLEARAGAIN: return Napi::String::New(env, "CLEARAGAIN");
    case SDLK_CRSEL: return Napi::String::New(env, "CRSEL");
    case SDLK_EXSEL: return Napi::String::New(env, "EXSEL");
    case SDLK_KP_00: return Napi::String::New(env, "KP_00");
    case SDLK_KP_000: return Napi::String::New(env, "KP_000");
    case SDLK_THOUSANDSSEPARATOR: return Napi::String::New(env, "THOUSANDSSEPARATOR");
    case SDLK_DECIMALSEPARATOR: return Napi::String::New(env, "DECIMALSEPARATOR");
    case SDLK_CURRENCYUNIT: return Napi::String::New(env, "CURRENCYUNIT");
    case SDLK_CURRENCYSUBUNIT: return Napi::String::New(env, "CURRENCYSUBUNIT");
    case SDLK_KP_LEFTPAREN: return Napi::String::New(env, "KP_LEFTPAREN");
    case SDLK_KP_RIGHTPAREN: return Napi::String::New(env, "KP_RIGHTPAREN");
    case SDLK_KP_LEFTBRACE: return Napi::String::New(env, "KP_LEFTBRACE");
    case SDLK_KP_RIGHTBRACE: return Napi::String::New(env, "KP_RIGHTBRACE");
    case SDLK_KP_TAB: return Napi::String::New(env, "KP_TAB");
    case SDLK_KP_BACKSPACE: return Napi::String::New(env, "KP_BACKSPACE");
    case SDLK_KP_A: return Napi::String::New(env, "KP_A");
    case SDLK_KP_B: return Napi::String::New(env, "KP_B");
    case SDLK_KP_C: return Napi::String::New(env, "KP_C");
    case SDLK_KP_D: return Napi::String::New(env, "KP_D");
    case SDLK_KP_E: return Napi::String::New(env, "KP_E");
    case SDLK_KP_F: return Napi::String::New(env, "KP_F");
    case SDLK_KP_XOR: return Napi::String::New(env, "KP_XOR");
    case SDLK_KP_POWER: return Napi::String::New(env, "KP_POWER");
    case SDLK_KP_PERCENT: return Napi::String::New(env, "KP_PERCENT");
    case SDLK_KP_LESS: return Napi::String::New(env, "KP_LESS");
    case SDLK_KP_GREATER: return Napi::String::New(env, "KP_GREATER");
    case SDLK_KP_AMPERSAND: return Napi::String::New(env, "KP_AMPERSAND");
    case SDLK_KP_DBLAMPERSAND: return Napi::String::New(env, "KP_DBLAMPERSAND");
    case SDLK_KP_VERTICALBAR: return Napi::String::New(env, "KP_VERTICALBAR");
    case SDLK_KP_DBLVERTICALBAR: return Napi::String::New(env, "KP_DBLVERTICALBAR");
    case SDLK_KP_COLON: return Napi::String::New(env, "KP_COLON");
    case SDLK_KP_HASH: return Napi::String::New(env, "KP_HASH");
    case SDLK_KP_SPACE: return Napi::String::New(env, "KP_SPACE");
    case SDLK_KP_AT: return Napi::String::New(env, "KP_AT");
    case SDLK_KP_EXCLAM: return Napi::String::New(env, "KP_EXCLAM");
    case SDLK_KP_MEMSTORE: return Napi::String::New(env, "KP_MEMSTORE");
    case SDLK_KP_MEMRECALL: return Napi::String::New(env, "KP_MEMRECALL");
    case SDLK_KP_MEMCLEAR: return Napi::String::New(env, "KP_MEMCLEAR");
    case SDLK_KP_MEMADD: return Napi::String::New(env, "KP_MEMADD");
    case SDLK_KP_MEMSUBTRACT: return Napi::String::New(env, "KP_MEMSUBTRACT");
    case SDLK_KP_MEMMULTIPLY: return Napi::String::New(env, "KP_MEMMULTIPLY");
    case SDLK_KP_MEMDIVIDE: return Napi::String::New(env, "KP_MEMDIVIDE");
    case SDLK_KP_PLUSMINUS: return Napi::String::New(env, "KP_PLUSMINUS");
    case SDLK_KP_CLEAR: return Napi::String::New(env, "KP_CLEAR");
    case SDLK_KP_CLEARENTRY: return Napi::String::New(env, "KP_CLEARENTRY");
    case SDLK_KP_BINARY: return Napi::String::New(env, "KP_BINARY");
    case SDLK_KP_OCTAL: return Napi::String::New(env, "KP_OCTAL");
    case SDLK_KP_DECIMAL: return Napi::String::New(env, "KP_DECIMAL");
    case SDLK_KP_HEXADECIMAL: return Napi::String::New(env, "KP_HEXADECIMAL");
    case SDLK_LCTRL: return Napi::String::New(env, "LCTRL");
    case SDLK_LSHIFT: return Napi::String::New(env, "LSHIFT");
    case SDLK_LALT: return Napi::String::New(env, "LALT");
    case SDLK_LGUI: return Napi::String::New(env, "LGUI");
    case SDLK_RCTRL: return Napi::String::New(env, "RCTRL");
    case SDLK_RSHIFT: return Napi::String::New(env, "RSHIFT");
    case SDLK_RALT: return Napi::String::New(env, "RALT");
    case SDLK_RGUI: return Napi::String::New(env, "RGUI");
    case SDLK_MODE: return Napi::String::New(env, "MODE");
    case SDLK_AUDIONEXT: return Napi::String::New(env, "AUDIONEXT");
    case SDLK_AUDIOPREV: return Napi::String::New(env, "AUDIOPREV");
    case SDLK_AUDIOSTOP: return Napi::String::New(env, "AUDIOSTOP");
    case SDLK_AUDIOPLAY: return Napi::String::New(env, "AUDIOPLAY");
    case SDLK_AUDIOMUTE: return Napi::String::New(env, "AUDIOMUTE");
    case SDLK_MEDIASELECT: return Napi::String::New(env, "MEDIASELECT");
    case SDLK_WWW: return Napi::String::New(env, "WWW");
    case SDLK_MAIL: return Napi::String::New(env, "MAIL");
    case SDLK_CALCULATOR: return Napi::String::New(env, "CALCULATOR");
    case SDLK_COMPUTER: return Napi::String::New(env, "COMPUTER");
    case SDLK_AC_SEARCH: return Napi::String::New(env, "AC_SEARCH");
    case SDLK_AC_HOME: return Napi::String::New(env, "AC_HOME");
    case SDLK_AC_BACK: return Napi::String::New(env, "AC_BACK");
    case SDLK_AC_FORWARD: return Napi::String::New(env, "AC_FORWARD");
    case SDLK_AC_STOP: return Napi::String::New(env, "AC_STOP");
    case SDLK_AC_REFRESH: return Napi::String::New(env, "AC_REFRESH");
    case SDLK_AC_BOOKMARKS: return Napi::String::New(env, "AC_BOOKMARKS");
    case SDLK_BRIGHTNESSDOWN: return Napi::String::New(env, "BRIGHTNESSDOWN");
    case SDLK_BRIGHTNESSUP: return Napi::String::New(env, "BRIGHTNESSUP");
    case SDLK_DISPLAYSWITCH: return Napi::String::New(env, "DISPLAYSWITCH");
    case SDLK_KBDILLUMTOGGLE: return Napi::String::New(env, "KBDILLUMTOGGLE");
    case SDLK_KBDILLUMDOWN: return Napi::String::New(env, "KBDILLUMDOWN");
    case SDLK_KBDILLUMUP: return Napi::String::New(env, "KBDILLUMUP");
    case SDLK_EJECT: return Napi::String::New(env, "EJECT");
    case SDLK_SLEEP: return Napi::String::New(env, "SLEEP");
    case SDLK_APP1: return Napi::String::New(env, "APP1");
    case SDLK_APP2: return Napi::String::New(env, "APP2");
    case SDLK_AUDIOREWIND: return Napi::String::New(env, "AUDIOREWIND");
    case SDLK_AUDIOFASTFORWARD: return Napi::String::New(env, "AUDIOFASTFORWARD");
  }

  return Napi::String::New(env, "FATAL ERROR");
}
