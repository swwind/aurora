const aurora = require('..');

aurora.bindKeyEventCallback((e) => {
  console.log(e.type, e.key)
});

aurora.bindMouseEventCallback((e) => {
  console.log(e.type, e.x, e.y);
  if (e.type == 'mousedown' || e.type == 'mouseup') {
    console.log(e.button);
  }
  if (e.type == 'mousewheel') {
    console.log(e.dx, e.dy);
  }
});

aurora.bindWindowEventCallback((e) => {
  console.log('window event', e.type);
  if (e.type === 'quit') {
    aurora.quit();
  }
  if (e.type === 'windowmoved') {
    console.log('new pos:', e.x, e.y);
  }
  if (e.type === 'windowresized' || e.type === 'windowsizechanged') {
    console.log('new size:', e.w, e.h);
  }
});

if (!aurora.init({
  title: 'hello world',
  w: 1280,
  h: 720,
  x: 'center',
  y: 'center',
  // resizable: true,
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
  const time = Date.now();
  const c1 = (Math.sin(time/5000) + 1) * 128;
  const c2 = (Math.sin(time/4000) + 1) * 128;
  const c3 = (Math.sin(time/3000) + 1) * 128;
  aurora.fillRect({
    color: aurora.color.rgb(c1, c2, c3),
    rect: {
      x: 200 + 200 * Math.sin(time / 500),
      y: 200 + 200 * Math.cos(time / 500),
      w: 50,
      h: 50,
    }
  });
  aurora.render();
}, 1000 / 60);
