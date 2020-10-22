type KKeyEvent = {
  type: 'keydown' | 'keyup';
  keycode: number;
  key: 'UNKNOWN' | 'RETURN' | 'ESCAPE' | 'BACKSPACE' | 'TAB' | 'SPACE' | 'EXCLAIM' | 'QUOTEDBL' | 'HASH' | 'PERCENT' | 'DOLLAR' | 'AMPERSAND' | 'QUOTE' | 'LEFTPAREN' | 'RIGHTPAREN' | 'ASTERISK' | 'PLUS' | 'COMMA' | 'MINUS' | 'PERIOD' | 'SLASH' | '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' | 'COLON' | 'SEMICOLON' | 'LESS' | 'EQUALS' | 'GREATER' | 'QUESTION' | 'AT' | 'LEFTBRACKET' | 'BACKSLASH' | 'RIGHTBRACKET' | 'CARET' | 'UNDERSCORE' | 'BACKQUOTE' | 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z' | 'CAPSLOCK' | 'F1' | 'F2' | 'F3' | 'F4' | 'F5' | 'F6' | 'F7' | 'F8' | 'F9' | 'F10' | 'F11' | 'F12' | 'PRINTSCREEN' | 'SCROLLLOCK' | 'PAUSE' | 'INSERT' | 'HOME' | 'PAGEUP' | 'DELETE' | 'END' | 'PAGEDOWN' | 'RIGHT' | 'LEFT' | 'DOWN' | 'UP' | 'NUMLOCKCLEAR' | 'KP_DIVIDE' | 'KP_MULTIPLY' | 'KP_MINUS' | 'KP_PLUS' | 'KP_ENTER' | 'KP_1' | 'KP_2' | 'KP_3' | 'KP_4' | 'KP_5' | 'KP_6' | 'KP_7' | 'KP_8' | 'KP_9' | 'KP_0' | 'KP_PERIOD' | 'APPLICATION' | 'POWER' | 'KP_EQUALS' | 'F13' | 'F14' | 'F15' | 'F16' | 'F17' | 'F18' | 'F19' | 'F20' | 'F21' | 'F22' | 'F23' | 'F24' | 'EXECUTE' | 'HELP' | 'MENU' | 'SELECT' | 'STOP' | 'AGAIN' | 'UNDO' | 'CUT' | 'COPY' | 'PASTE' | 'FIND' | 'MUTE' | 'VOLUMEUP' | 'VOLUMEDOWN' | 'KP_COMMA' | 'KP_EQUALSAS400' | 'ALTERASE' | 'SYSREQ' | 'CANCEL' | 'CLEAR' | 'PRIOR' | 'RETURN2' | 'SEPARATOR' | 'OUT' | 'OPER' | 'CLEARAGAIN' | 'CRSEL' | 'EXSEL' | 'KP_00' | 'KP_000' | 'THOUSANDSSEPARATOR' | 'DECIMALSEPARATOR' | 'CURRENCYUNIT' | 'CURRENCYSUBUNIT' | 'KP_LEFTPAREN' | 'KP_RIGHTPAREN' | 'KP_LEFTBRACE' | 'KP_RIGHTBRACE' | 'KP_TAB' | 'KP_BACKSPACE' | 'KP_A' | 'KP_B' | 'KP_C' | 'KP_D' | 'KP_E' | 'KP_F' | 'KP_XOR' | 'KP_POWER' | 'KP_PERCENT' | 'KP_LESS' | 'KP_GREATER' | 'KP_AMPERSAND' | 'KP_DBLAMPERSAND' | 'KP_VERTICALBAR' | 'KP_DBLVERTICALBAR' | 'KP_COLON' | 'KP_HASH' | 'KP_SPACE' | 'KP_AT' | 'KP_EXCLAM' | 'KP_MEMSTORE' | 'KP_MEMRECALL' | 'KP_MEMCLEAR' | 'KP_MEMADD' | 'KP_MEMSUBTRACT' | 'KP_MEMMULTIPLY' | 'KP_MEMDIVIDE' | 'KP_PLUSMINUS' | 'KP_CLEAR' | 'KP_CLEARENTRY' | 'KP_BINARY' | 'KP_OCTAL' | 'KP_DECIMAL' | 'KP_HEXADECIMAL' | 'LCTRL' | 'LSHIFT' | 'LALT' | 'LGUI' | 'RCTRL' | 'RSHIFT' | 'RALT' | 'RGUI' | 'MODE' | 'AUDIONEXT' | 'AUDIOPREV' | 'AUDIOSTOP' | 'AUDIOPLAY' | 'AUDIOMUTE' | 'MEDIASELECT' | 'WWW' | 'MAIL' | 'CALCULATOR' | 'COMPUTER' | 'AC_SEARCH' | 'AC_HOME' | 'AC_BACK' | 'AC_FORWARD' | 'AC_STOP' | 'AC_REFRESH' | 'AC_BOOKMARKS' | 'BRIGHTNESSDOWN' | 'BRIGHTNESSUP' | 'DISPLAYSWITCH' | 'KBDILLUMTOGGLE' | 'KBDILLUMDOWN' | 'KBDILLUMUP' | 'EJECT' | 'SLEEP' | 'APP1' | 'APP2' | 'AUDIOREWIND' | 'AUDIOFASTFORWARD';
}

type KMouseEvent = {
  x: number;
  y: number;
} & ({
  type: 'mousemove';
} | {
  type: 'mousedown' | 'mouseup';
  button: 'left' | 'middle' | 'right' | 'x1' | 'x2';
} | {
  type: 'mousewheel';
  dx: number;
  dy: number;
});

type KWindowEvent = {
  type: 'quit' | 'windownone' | 'windowshown' | 'windowhidden' | 'windowexposed' | 'windowminimized' | 'windowmaximized' | 'windowrestored' | 'windowenter' | 'windowleave' | 'windowfocusgained' | 'windowfocuslost' | 'windowclose' | 'windowtakefocus' | 'windowhittest';
} | {
  type: 'windowmoved';
  x: number;
  y: number;
} | {
  type: 'windowresized' | 'windowsizechanged';
  w: number;
  h: number;
}

type KKeyEventCallback = (e: KKeyEvent) => void;
type KMouseEventCallback = (e: KMouseEvent) => void;
type KWindowEventCallback = (e: KWindowEvent) => void;
type KClosedCallback = () => void;

type KColor = {
  r: number;
  g: number;
  b: number;
  a: number;
}

type KPoint = {
  x: number;
  y: number;
}

type KRect = {
  x: number;
  y: number;
  w: number;
  h: number;
}

type KDrawLineConfig = {
  color: KColor;
  start: KPoint;
  end: KPoint;
}

type KDrawPointConfig = {
  color: KColor;
  point: KPoint;
}

type KDrawRectConfig = {
  color: KColor;
  rect: KRect;
}

type KDrawImageConfig = {
  texture: number;
  srcrect?: KRect;
  dstrect?: KRect;
}

type KWindowConfig = {
  title: string;
  w: number;
  h: number;
  x?: number;
  y?: number;
  fullscreen?: boolean;
  opengl?: boolean;
  shown?: boolean;
  hidden?: boolean;
  borderless?: boolean;
  resizable?: boolean;
  minimized?: boolean;
  maximized?: boolean;
  input_grabbed?: boolean;
  input_focus?: boolean;
  mouse_focus?: boolean;
  fullscreen_desktop?: boolean;
  foreign?: boolean;
  allow_highdpi?: boolean;
  mouse_capture?: boolean;
  always_on_top?: boolean;
  skip_taskbar?: boolean;
  utility?: boolean;
  tooltip?: boolean;
  popup_menu?: boolean;
  vulkan?: boolean;
}

export function bindKeyEventCallback(fn: KKeyEventCallback): void;
export function bindMouseEventCallback(fn: KMouseEventCallback): void;
export function bindWindowEventCallback(fn: KWindowEventCallback): void;

export function startEventLoop(fn?: KClosedCallback): void;

export function drawLine(config: KDrawLineConfig): void;
export function drawPoint(config: KDrawPointConfig): void;
export function drawRect(config: KDrawRectConfig): void;
export function fillRect(config: KDrawRectConfig): void;
export function drawImage(config: KDrawImageConfig): void;

export function init(config: KWindowConfig): boolean;
export function quit(): void;
export function render(): void;
export function close(): void;

export function registerTexture(path: string): number;

export const color: {
  rgb(r: number, g: number, b: number): KColor;
  rgba(r: number, g: number, b: number, a: number): KColor;
  red: KColor;
  green: KColor;
  blue: KColor;
  white: KColor;
  black: KColor;
}
