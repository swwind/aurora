/**
 * Possible key types
 */
type KKeys = 'UNKNOWN' | 'RETURN' | 'ESCAPE' | 'BACKSPACE' | 'TAB' | 'SPACE' | 'EXCLAIM' | 'QUOTEDBL' | 'HASH' | 'PERCENT' | 'DOLLAR' | 'AMPERSAND' | 'QUOTE' | 'LEFTPAREN' | 'RIGHTPAREN' | 'ASTERISK' | 'PLUS' | 'COMMA' | 'MINUS' | 'PERIOD' | 'SLASH' | '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' | 'COLON' | 'SEMICOLON' | 'LESS' | 'EQUALS' | 'GREATER' | 'QUESTION' | 'AT' | 'LEFTBRACKET' | 'BACKSLASH' | 'RIGHTBRACKET' | 'CARET' | 'UNDERSCORE' | 'BACKQUOTE' | 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h' | 'i' | 'j' | 'k' | 'l' | 'm' | 'n' | 'o' | 'p' | 'q' | 'r' | 's' | 't' | 'u' | 'v' | 'w' | 'x' | 'y' | 'z' | 'CAPSLOCK' | 'F1' | 'F2' | 'F3' | 'F4' | 'F5' | 'F6' | 'F7' | 'F8' | 'F9' | 'F10' | 'F11' | 'F12' | 'PRINTSCREEN' | 'SCROLLLOCK' | 'PAUSE' | 'INSERT' | 'HOME' | 'PAGEUP' | 'DELETE' | 'END' | 'PAGEDOWN' | 'RIGHT' | 'LEFT' | 'DOWN' | 'UP' | 'NUMLOCKCLEAR' | 'KP_DIVIDE' | 'KP_MULTIPLY' | 'KP_MINUS' | 'KP_PLUS' | 'KP_ENTER' | 'KP_1' | 'KP_2' | 'KP_3' | 'KP_4' | 'KP_5' | 'KP_6' | 'KP_7' | 'KP_8' | 'KP_9' | 'KP_0' | 'KP_PERIOD' | 'APPLICATION' | 'POWER' | 'KP_EQUALS' | 'F13' | 'F14' | 'F15' | 'F16' | 'F17' | 'F18' | 'F19' | 'F20' | 'F21' | 'F22' | 'F23' | 'F24' | 'EXECUTE' | 'HELP' | 'MENU' | 'SELECT' | 'STOP' | 'AGAIN' | 'UNDO' | 'CUT' | 'COPY' | 'PASTE' | 'FIND' | 'MUTE' | 'VOLUMEUP' | 'VOLUMEDOWN' | 'KP_COMMA' | 'KP_EQUALSAS400' | 'ALTERASE' | 'SYSREQ' | 'CANCEL' | 'CLEAR' | 'PRIOR' | 'RETURN2' | 'SEPARATOR' | 'OUT' | 'OPER' | 'CLEARAGAIN' | 'CRSEL' | 'EXSEL' | 'KP_00' | 'KP_000' | 'THOUSANDSSEPARATOR' | 'DECIMALSEPARATOR' | 'CURRENCYUNIT' | 'CURRENCYSUBUNIT' | 'KP_LEFTPAREN' | 'KP_RIGHTPAREN' | 'KP_LEFTBRACE' | 'KP_RIGHTBRACE' | 'KP_TAB' | 'KP_BACKSPACE' | 'KP_A' | 'KP_B' | 'KP_C' | 'KP_D' | 'KP_E' | 'KP_F' | 'KP_XOR' | 'KP_POWER' | 'KP_PERCENT' | 'KP_LESS' | 'KP_GREATER' | 'KP_AMPERSAND' | 'KP_DBLAMPERSAND' | 'KP_VERTICALBAR' | 'KP_DBLVERTICALBAR' | 'KP_COLON' | 'KP_HASH' | 'KP_SPACE' | 'KP_AT' | 'KP_EXCLAM' | 'KP_MEMSTORE' | 'KP_MEMRECALL' | 'KP_MEMCLEAR' | 'KP_MEMADD' | 'KP_MEMSUBTRACT' | 'KP_MEMMULTIPLY' | 'KP_MEMDIVIDE' | 'KP_PLUSMINUS' | 'KP_CLEAR' | 'KP_CLEARENTRY' | 'KP_BINARY' | 'KP_OCTAL' | 'KP_DECIMAL' | 'KP_HEXADECIMAL' | 'LCTRL' | 'LSHIFT' | 'LALT' | 'LGUI' | 'RCTRL' | 'RSHIFT' | 'RALT' | 'RGUI' | 'MODE' | 'AUDIONEXT' | 'AUDIOPREV' | 'AUDIOSTOP' | 'AUDIOPLAY' | 'AUDIOMUTE' | 'MEDIASELECT' | 'WWW' | 'MAIL' | 'CALCULATOR' | 'COMPUTER' | 'AC_SEARCH' | 'AC_HOME' | 'AC_BACK' | 'AC_FORWARD' | 'AC_STOP' | 'AC_REFRESH' | 'AC_BOOKMARKS' | 'BRIGHTNESSDOWN' | 'BRIGHTNESSUP' | 'DISPLAYSWITCH' | 'KBDILLUMTOGGLE' | 'KBDILLUMDOWN' | 'KBDILLUMUP' | 'EJECT' | 'SLEEP' | 'APP1' | 'APP2' | 'AUDIOREWIND' | 'AUDIOFASTFORWARD';

/**
 * Key event
 */
type KKeyEvent = {
  /**
   * Key event type
   */
  type: 'keydown' | 'keyup';
  /**
   * Key code as number
   */
  keycode: number;
  /**
   * Key code as string
   */
  key: KKeys;
}

/**
 * Mouse event
 */
type KMouseEvent = {
  x: number;
  y: number;
} & ({
  /**
   * Mouse event type
   */
  type: 'mousemove';
} | {
  /**
   * Mouse event type
   */
  type: 'mousedown' | 'mouseup';
  /**
   * Clicked button
   */
  button: 'left' | 'middle' | 'right' | 'x1' | 'x2';
} | {
  /**
   * Mouse event type
   */
  type: 'mousewheel';
  /**
   * delta x
   */
  dx: number;
  /**
   * delta y
   */
  dy: number;
});

/**
 * Window event
 */
type KWindowEvent = {
  /**
   * Window event type
   */
  type: 'quit' | 'windownone' | 'windowshown' | 'windowhidden' | 'windowexposed' | 'windowminimized' | 'windowmaximized' | 'windowrestored' | 'windowenter' | 'windowleave' | 'windowfocusgained' | 'windowfocuslost' | 'windowclose' | 'windowtakefocus' | 'windowhittest';
} | {
  /**
   * Window event type
   */
  type: 'windowmoved';
  /**
   * window moved to (x, y)
   */
  x: number;
  /**
   * window moved to (x, y)
   */
  y: number;
} | {
  /**
   * Window event type
   */
  type: 'windowresized' | 'windowsizechanged';
  /**
   * window resized to W x H
   */
  w: number;
  /**
   * window resized to W x H
   */
  h: number;
}

/**
 * Key event callback
 */
type KKeyEventCallback = (e: KKeyEvent) => void;
/**
 * Mouse event callback
 */
type KMouseEventCallback = (e: KMouseEvent) => void;
/**
 * Window event callback
 */
type KWindowEventCallback = (e: KWindowEvent) => void;
/**
 * Aurora closed callback
 */
type KClosedCallback = () => void;

/**
 * A color. `r`, `g`, `b`, `a` must be int8 type([0, 255]).
 */
type KColor = {
  r: number;
  g: number;
  b: number;
  a: number;
}

/**
 * A point
 */
type KPoint = {
  x: number;
  y: number;
}

/**
 * A rectangle
 */
type KRect = {
  x: number;
  y: number;
  w: number;
  h: number;
}

/**
 * A texture
 */
type KTexture = {
  /**
   * Texture unique id, original texture was saved inside
   * C++ code, used this id to refer to that saved texture.
   */
  id: number;
  /**
   * Texture width
   */
  width: number;
  /**
   * Texture height
   */
  height: number;
}

/**
 * A font
 */
type KFont = {
  /**
   * Unique font id
   */
  id: number;
  /**
   * font size
   */
  size: number;
}

/**
 * A piece of music
 */
type KMusic = { id: number; };
/**
 * A piece of sound
 */
type KSound = { id: number; };

/**
 * Init window config
 */
type KWindowConfig = {
  /**
   * Window title
   */
  title: string;
  /**
   * Window width
   */
  w: number;
  /**
   * Window height
   */
  h: number;
  /**
   * Window x position
   * @default center
   */
  x?: number;
  /**
   * Window y position
   * @default center
   */
  y?: number;

  /**
   * Modify screen resolution to width x height
   * and run as fullscreen
   * @default false
   */
  fullscreen?: boolean;
  /**
   * Use openGL
   * @default false
   */
  opengl?: boolean;
  /**
   * Show that window
   * @default true
   */
  shown?: boolean;
  /**
   * Hide that window
   * @default false
   */
  hidden?: boolean;
  /**
   * Create window without border
   * @default false
   */
  borderless?: boolean;
  /**
   * Make window resizable
   * @default false
   */
  resizable?: boolean;
  /**
   * Minimized window
   * @default false
   */
  minimized?: boolean;
  /**
   * Maximized window
   * @default false
   */
  maximized?: boolean;
  /**
   * ???
   * @default false
   */
  input_grabbed?: boolean;
  /**
   * ???
   * @default false
   */
  input_focus?: boolean;
  /**
   * ???
   * @default false
   */
  mouse_focus?: boolean;
  /**
   * ???
   * @default false
   */
  fullscreen_desktop?: boolean;
  /**
   * ???
   * @default false
   */
  foreign?: boolean;
  /**
   * ???
   * @default false
   */
  allow_highdpi?: boolean;
  /**
   * ???
   * @default false
   */
  mouse_capture?: boolean;
  /**
   * Always on top
   * @default false
   */
  always_on_top?: boolean;
  /**
   * ???
   * @default false
   */
  skip_taskbar?: boolean;
  /**
   * ???
   * @default false
   */
  utility?: boolean;
  /**
   * ???
   * @default false
   */
  tooltip?: boolean;
  /**
   * ???
   * @default false
   */
  popup_menu?: boolean;
  /**
   * ???
   * @default false
   */
  vulkan?: boolean;
  /**
   * Anti alias
   * @default false
   */
  antialias?: boolean;
}

/**
 * listen key events
 * @param fn callback
 */
export function bindKeyEventCallback(fn: KKeyEventCallback): void;
/**
 * listen mouse events
 * @param fn callback
 */
export function bindMouseEventCallback(fn: KMouseEventCallback): void;
/**
 * listen window events
 * @param fn callback
 */
export function bindWindowEventCallback(fn: KWindowEventCallback): void;

/**
 * Start event loops. You MUST have invoked `aurora.init` first.
 * @param fn window closed callback
 */
export function startEventLoop(fn?: KClosedCallback): void;

/**
 * Draw a line
 * @param start start point
 * @param end end point
 * @param color line color
 */
export function drawLine(start: KPoint, end: KPoint, color: KColor): void;
/**
 * Draw a point
 * @param point point
 * @param color color
 */
export function drawPoint(point: KPoint, color: KColor): void;
/**
 * Draw a rectangle (border only)
 * @param rect rectangle
 * @param color color
 */
export function drawRect(rect: KRect, color: KColor): void;
/**
 * Fill a rectangle with specific color
 * @param rect rectangle
 * @param color color
 */
export function fillRect(rect: KRect, color: KColor): void;
/**
 * Draw an image on window
 * @param texture_id texture unique id
 * @param dstrect rect of window, default all
 * @param srcrect rect of picture, default all
 * @param degree rotate degree, default 0
 * @param anchor rotate center, default (w/2, h/2)
 */
export function drawImage(texture_id: number, dstrect?: KRect, srcrect?: KRect, degree?: number, anchor?: KPoint): void;

/**
 * Initialize window
 * @param config configuration
 */
export function init(config: KWindowConfig): boolean;
/**
 * Quit event loop (DOES NOT close window)
 */
export function quit(): void;
/**
 * Render to window
 */
export function render(): void;
/**
 * Close the window (MUST quit event loop first)
 */
export function close(): void;

/**
 * Preload a texture
 * @param src source path
 */
export function registerTexture(src: string): KTexture;
/**
 * Preload a piece of music
 * @param src source path
 */
export function registerMusic(src: string): KMusic;
/**
 * Preload a piece of sound
 * @param src source path
 */
export function registerSound(src: string): KSound;
/**
 * Preload a font
 * @param src source path
 */
export function registerFont(src: string, size: number): KFont;
/**
 * Render text and save as texture
 * @param font_id font unique id
 * @param text text
 * @param color text color
 * @param width max width
 */
export function renderText(font_id: number, text: string, color: KColor, width: number): KTexture;
export function deleteTexture(texture_id: number): void;
export function deleteFont(font_id: number): void;
export function deleteMusic(music_id: number): void;
export function deleteSound(sound_id: number): void;
export function setTextureAlpha(texture_id: number, alpha: number): void;

/**
 * Play a music
 * @param music_id music unique id
 * @param loops loop, `-1` play forever
 */
export function playMusic(music_id: number, loops: number): void;
/**
 * Pause music
 */
export function pauseMusic(): void;
/**
 * Resume music
 */
export function resumeMusic(): void;
/**
 * Toggle music
 */
export function toggleMusic(): void;
/**
 * 
 * @param sound_id sound unique id
 * @param channel channel id, `-1` for first available channel
 * @param loops loop, `-1` play forever
 */
export function playSound(sound_id: number, channel: number, loops: number): void;

export const color: {
  /**
   * A color of RGB
   * @param r red
   * @param g green
   * @param b blue
   */
  rgb(r: number, g: number, b: number): KColor;
  /**
   * A color of RGBA
   * @param r red
   * @param g green
   * @param b blue
   * @param a alpha
   */
  rgba(r: number, g: number, b: number, a: number): KColor;
  red: KColor;
  green: KColor;
  blue: KColor;
  white: KColor;
  black: KColor;
}
