const aurora = require('..');

const keys = { };

aurora.bindKeyEventCallback((e) => {
  if (e.type === "keydown") {
    keys[e.key] = true;
  } else if (e.type === "keyup") {
    keys[e.key] = false;
  }
});

if (!aurora.init()) {
  console.log('failed to create window');
  process.exit(1);
} else {
  aurora.startEventLoop(() => {
    process.exit(0);
  });
}

let x = 100, y = 100;
let lasttime = Date.now();
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
    color: aurora.color.rgb(c1, c2, c3),
    rect: {
      x,
      y,
      w: 50,
      h: 50,
    }
  });
  aurora.render();
}, 1000 / 60);
