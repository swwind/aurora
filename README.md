# Aurora

This is a game engine based on SDL2.

**WIP**

## Install

You need to install `SDL2`, `SDL2_image`, `SDL2_ttf` and `SDL2_mixer` first.

On **ArchLinux**, just install them by using `pacman`:

```bash
sudo pacman -S sdl2 sdl2_image sdl2_ttf sdl2_mixer
```

Then, you can add `@swwind/aurora` to you project.

```bash
yarn add @swwind/aurora
```

On **Windows**, I don't know how to build it.

Try it yourself!

## Usage

```js
const aurora = require('@swwind/aurora');

// initialize the window
// more configs see aurora.d.ts
const success = aurora.init({
  title: 'hello world',
  w: 1280,
  h: 720,
});

// handle error
if (!success) {
  console.error('failed to initialize');
  process.exit(1);
}

// listen window events
aurora.bindWindowEventCallback((e) => {
  // handle quit event
  if (e.type === 'quit') {
    // quit event loop
    aurora.quit();
  }
});

// start event loop
aurora.startEventLoop(() => {
  // callback when event loop quitted

  // close the window manually
  aurora.close();
  // and exit the process
  process.exit(0);
});

// render interval
// like requestAnimationFrame
setInterval(() => {
  // fill the whole window with white color
  aurora.fillRect({ x: 0, y: 0, w: 1280, h: 720 }, aurora.color.white);
  // render to window
  aurora.render();
}, 1000 / 60); // 60 fps
```

## TODOs

- [x] SDL2 image
- [x] SDL2 ttf
- [x] SDL2 mixer
- [ ] Documents
- [ ] Error handler
- [ ] Build on windows
- [ ] Release method
