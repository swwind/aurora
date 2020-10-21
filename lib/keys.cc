#include "keys.h"

std::string getEventType(uint32_t type) {
	switch (type) {
	case SDL_KEYDOWN: return "keydown";
	case SDL_KEYUP: return "keyup";
	case SDL_MOUSEBUTTONDOWN: return "mousedown";
	case SDL_MOUSEBUTTONUP: return "mouseup";
	case SDL_MOUSEWHEEL: return "mousewheel";
	case SDL_MOUSEMOTION: return "mousemove";
	}
	return "unknown";
}

std::string getMouseType(uint8_t type) {
  switch (type) {
  case SDL_BUTTON_MIDDLE: return "middle";
  case SDL_BUTTON_LEFT: return "left";
  case SDL_BUTTON_RIGHT: return "right";
  case SDL_BUTTON_X1: return "x1";
  case SDL_BUTTON_X2: return "x2";
  }
  return "unknown";
}

#define key(a) \
  case SDLK_ ## a: return #a

std::string getKeyCode(uint32_t x) {
  switch (x) {
    key(UNKNOWN);
    key(RETURN);
    key(ESCAPE);
    key(BACKSPACE);
    key(TAB);
    key(SPACE);
    key(EXCLAIM);
    key(QUOTEDBL);
    key(HASH);
    key(PERCENT);
    key(DOLLAR);
    key(AMPERSAND);
    key(QUOTE);
    key(LEFTPAREN);
    key(RIGHTPAREN);
    key(ASTERISK);
    key(PLUS);
    key(COMMA);
    key(MINUS);
    key(PERIOD);
    key(SLASH);
    key(0);
    key(1);
    key(2);
    key(3);
    key(4);
    key(5);
    key(6);
    key(7);
    key(8);
    key(9);
    key(COLON);
    key(SEMICOLON);
    key(LESS);
    key(EQUALS);
    key(GREATER);
    key(QUESTION);
    key(AT);
    key(LEFTBRACKET);
    key(BACKSLASH);
    key(RIGHTBRACKET);
    key(CARET);
    key(UNDERSCORE);
    key(BACKQUOTE);
    key(a);
    key(b);
    key(c);
    key(d);
    key(e);
    key(f);
    key(g);
    key(h);
    key(i);
    key(j);
    key(k);
    key(l);
    key(m);
    key(n);
    key(o);
    key(p);
    key(q);
    key(r);
    key(s);
    key(t);
    key(u);
    key(v);
    key(w);
    key(x);
    key(y);
    key(z);
    key(CAPSLOCK);
    key(F1);
    key(F2);
    key(F3);
    key(F4);
    key(F5);
    key(F6);
    key(F7);
    key(F8);
    key(F9);
    key(F10);
    key(F11);
    key(F12);
    key(PRINTSCREEN);
    key(SCROLLLOCK);
    key(PAUSE);
    key(INSERT);
    key(HOME);
    key(PAGEUP);
    key(DELETE);
    key(END);
    key(PAGEDOWN);
    key(RIGHT);
    key(LEFT);
    key(DOWN);
    key(UP);
    key(NUMLOCKCLEAR);
    key(KP_DIVIDE);
    key(KP_MULTIPLY);
    key(KP_MINUS);
    key(KP_PLUS);
    key(KP_ENTER);
    key(KP_1);
    key(KP_2);
    key(KP_3);
    key(KP_4);
    key(KP_5);
    key(KP_6);
    key(KP_7);
    key(KP_8);
    key(KP_9);
    key(KP_0);
    key(KP_PERIOD);
    key(APPLICATION);
    key(POWER);
    key(KP_EQUALS);
    key(F13);
    key(F14);
    key(F15);
    key(F16);
    key(F17);
    key(F18);
    key(F19);
    key(F20);
    key(F21);
    key(F22);
    key(F23);
    key(F24);
    key(EXECUTE);
    key(HELP);
    key(MENU);
    key(SELECT);
    key(STOP);
    key(AGAIN);
    key(UNDO);
    key(CUT);
    key(COPY);
    key(PASTE);
    key(FIND);
    key(MUTE);
    key(VOLUMEUP);
    key(VOLUMEDOWN);
    key(KP_COMMA);
    key(KP_EQUALSAS400);
    key(ALTERASE);
    key(SYSREQ);
    key(CANCEL);
    key(CLEAR);
    key(PRIOR);
    key(RETURN2);
    key(SEPARATOR);
    key(OUT);
    key(OPER);
    key(CLEARAGAIN);
    key(CRSEL);
    key(EXSEL);
    key(KP_00);
    key(KP_000);
    key(THOUSANDSSEPARATOR);
    key(DECIMALSEPARATOR);
    key(CURRENCYUNIT);
    key(CURRENCYSUBUNIT);
    key(KP_LEFTPAREN);
    key(KP_RIGHTPAREN);
    key(KP_LEFTBRACE);
    key(KP_RIGHTBRACE);
    key(KP_TAB);
    key(KP_BACKSPACE);
    key(KP_A);
    key(KP_B);
    key(KP_C);
    key(KP_D);
    key(KP_E);
    key(KP_F);
    key(KP_XOR);
    key(KP_POWER);
    key(KP_PERCENT);
    key(KP_LESS);
    key(KP_GREATER);
    key(KP_AMPERSAND);
    key(KP_DBLAMPERSAND);
    key(KP_VERTICALBAR);
    key(KP_DBLVERTICALBAR);
    key(KP_COLON);
    key(KP_HASH);
    key(KP_SPACE);
    key(KP_AT);
    key(KP_EXCLAM);
    key(KP_MEMSTORE);
    key(KP_MEMRECALL);
    key(KP_MEMCLEAR);
    key(KP_MEMADD);
    key(KP_MEMSUBTRACT);
    key(KP_MEMMULTIPLY);
    key(KP_MEMDIVIDE);
    key(KP_PLUSMINUS);
    key(KP_CLEAR);
    key(KP_CLEARENTRY);
    key(KP_BINARY);
    key(KP_OCTAL);
    key(KP_DECIMAL);
    key(KP_HEXADECIMAL);
    key(LCTRL);
    key(LSHIFT);
    key(LALT);
    key(LGUI);
    key(RCTRL);
    key(RSHIFT);
    key(RALT);
    key(RGUI);
    key(MODE);
    key(AUDIONEXT);
    key(AUDIOPREV);
    key(AUDIOSTOP);
    key(AUDIOPLAY);
    key(AUDIOMUTE);
    key(MEDIASELECT);
    key(WWW);
    key(MAIL);
    key(CALCULATOR);
    key(COMPUTER);
    key(AC_SEARCH);
    key(AC_HOME);
    key(AC_BACK);
    key(AC_FORWARD);
    key(AC_STOP);
    key(AC_REFRESH);
    key(AC_BOOKMARKS);
    key(BRIGHTNESSDOWN);
    key(BRIGHTNESSUP);
    key(DISPLAYSWITCH);
    key(KBDILLUMTOGGLE);
    key(KBDILLUMDOWN);
    key(KBDILLUMUP);
    key(EJECT);
    key(SLEEP);
    key(APP1);
    key(APP2);
    key(AUDIOREWIND);
    key(AUDIOFASTFORWARD);
  }

  return "FATAL ERROR";
}
