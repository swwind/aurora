const aurora = require('..');

const keys = { };
let hover = false;
let x = 100, y = 100, w = 50, h = 50;
let lasttime = Date.now();

aurora.bindKeyEventCallback((e) => {
  if (e.type === "keydown") {
    keys[e.key] = true;
  } else if (e.type === "keyup") {
    keys[e.key] = false;
  }
});
aurora.bindMouseEventCallback((e) => {
  if (e.type === 'mousemove') {
    if (e.x >= x && e.y >= y && e.x <= x + 50 && e.y <= y + 50) {
      hover = true;
    } else {
      hover = false;
    }
  }
  if (e.type === 'mousewheel') {
    w = Math.max(0, w + 5 * e.dy);
    h = Math.max(0, h + 5 * e.dy);
  }
});
aurora.bindWindowEventCallback((e) => {
  if (e.type === 'quit') {
    aurora.quit();
  }
});

if (!aurora.init({
  title: 'Genshin Impact',
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

const huaji = aurora.registerTexture('example/huaji.png');

setInterval(() => {
  const time = Date.now();
  if (keys["w"] || keys["UP"])    { y -= 0.5 * (time - lasttime); }
  if (keys["s"] || keys["DOWN"])  { y += 0.5 * (time - lasttime); }
  if (keys["a"] || keys["LEFT"])  { x -= 0.5 * (time - lasttime); }
  if (keys["d"] || keys["RIGHT"]) { x += 0.5 * (time - lasttime); }
  lasttime = time;
  aurora.fillRect({
    color: aurora.color.white,
    rect: { x: 0, y: 0, w: 1280, h: 720 },
  });
  aurora.drawImage({ texture: huaji, dstrect: { x, y, w, h } });
  aurora.render();
}, 1000 / 60);
