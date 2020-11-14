const aurora = require('..');

const keys = { };
let x = 100, y = 100, w = 50, h = 50;
let lasttime = Date.now();

let mx = null, my = null;

if (!aurora.init({
  title: 'Genshin Impact',
  w: 1280,
  h: 720,
  opengl: true,
  // fullscreen: true,
})) {
  console.log('failed to create window');
  process.exit(1);
}

aurora.bindKeyEventCallback((e) => {
  if (e.type === "keydown") {
    keys[e.key] = true;
  } else if (e.type === "keyup") {
    keys[e.key] = false;
  }

  if (e.type === 'keydown' && e.key === 'p') {
    aurora.toggleMusic();
  }
});
aurora.bindMouseEventCallback((e) => {
  if (e.type === 'mousewheel') {
    w = Math.max(0, w + 5 * e.dy);
    h = Math.max(0, h + 5 * e.dy);
  }
});
aurora.bindWindowEventCallback((e) => {
  if (e.type === 'quit') {
    aurora.close();
  }
  if (e.type === "windowmoved") {
    if (mx != null) { x -= e.x - mx; }
    if (my != null) { y -= e.y - my; }
    mx = e.x; my = e.y;
  }
});

aurora.startEventLoop(() => {
  // aurora.close();
  process.exit(0);
});

const huaji = aurora.registerTexture('example/assets/huaji.png');
const genshin = aurora.registerFont('tmp/genshin.ttf', 42);
const fonts = aurora.renderText(genshin.id, '你是不是瞧不起中文？？？', aurora.color.black, 300);
console.log(fonts);
const flac = aurora.registerMusic('tmp/aurora.wav');

aurora.bindMouseEventCallback((e) => {
  if (e.type == 'mousedown') {
    if (e.x >= x && e.y >= y && e.x <= x+w && e.y <= y+h) {
      // click on the image
      aurora.playMusic(flac.id, -1);
    }
  }
});

setInterval(() => {
  const time = Date.now();
  const step = time - lasttime;
  if (keys["w"] || keys["UP"])    { y -= 0.5 * step; }
  if (keys["s"] || keys["DOWN"])  { y += 0.5 * step; }
  if (keys["a"] || keys["LEFT"])  { x -= 0.5 * step; }
  if (keys["d"] || keys["RIGHT"]) { x += 0.5 * step; }
  lasttime = time;

  aurora.setTextureAlpha(huaji.id, Math.floor(Math.abs(Math.sin(time / 500)) * 0xff));
  aurora.fillRect({ x: 0, y: 0, w: 1280, h: 720 }, aurora.color.white);
  aurora.drawImage(fonts.id, { x: 0, y: 0, w: fonts.width, h: fonts.height });
  aurora.drawImage(huaji.id, { x, y, w, h });
  aurora.render();
}, 1000 / 60);
