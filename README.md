# Aurora

This is a game engine based on SDL2.

**WIP**

```js
const aurora = require('@swwind/aurora');

aurora.bindWindowEventCallback((e) => {
  if (e.type === 'quit') {
    aurora.quit();
  }
});

if (!aurora.init({
  title: 'hello world',
  w: 1280,
  h: 720,
})) {
  console.log('failed to create window');
  process.exit(1);
}

aurora.startEventLoop(() => {
  // app quitted
  aurora.close();
  process.exit(0);
});

setInterval(() => {
  aurora.fillRect({ x: 0, y: 0, w: 1280, h: 720 }, aurora.color.white);
  aurora.render();
}, 1000 / 60);
```

## Install

You need to install `SDL2`, `SDL2_image`, `SDL2_ttf` and `SDL2_mixer` first.

On **ArchLinux**, just install them by using `pacman`:

```bash
sudo pacman -S sdl2 sdl2_image sdl2_ttf sdl2_mixer
```

Then, you can try to run the example:

```bash
yarn
yarn build
yarn test
```

## TODOs

- [x] SDL2 image
- [x] SDL2 ttf
- [x] SDL2 mixer
- [ ] Documents
- [ ] Error handler
- [ ] Build on windows
- [ ] Release method
