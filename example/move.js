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

if (!aurora.init()) {
  console.log('failed to create window');
  process.exit(1);
} else {
  aurora.startEventLoop();
}

setInterval(() => {
  const time = Date.now();
  if (keys["w"]) {
    y -= 0.5 * (time - lasttime);
  }
  if (keys["s"]) {
    y += 0.5 * (time - lasttime);
  }
  if (keys["a"]) {
    x -= 0.5 * (time - lasttime);
  }
  if (keys["d"]) {
    x += 0.5 * (time - lasttime);
  }
  lasttime = time;
  const c1 = (Math.sin(time/5000) + 1) * 128;
  const c2 = (Math.sin(time/4000) + 1) * 128;
  const c3 = (Math.sin(time/3000) + 1) * 128;
  aurora.fillRect({
    color: hover ? aurora.color.blue : aurora.color.rgb(c1, c2, c3),
    rect: { x, y, w, h }
  });
  aurora.render();
}, 1000 / 60);
