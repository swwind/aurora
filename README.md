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
} else {
  aurora.startEventLoop(() => {
    aurora.close();
    process.exit(0);
  });
}

setInterval(() => {
  aurora.fillRect({
    color: aurora.color.white,
    rect: { x: 0, y: 0, w: 1280, h: 720 },
  });
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

- [ ] SDL2 mixer
- [ ] Error handler
- [ ] Build on windows
