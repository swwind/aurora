function rgb(r, g, b) {
  return { r, g, b, a: 0xff };
}
function rgba(r, g, b, a) {
  return { r, g, b, a };
}
const blue = rgb(0, 0, 0xff);
const green = rgb(0, 0xff, 0);
const red = rgb(0, 0xff, 0);

module.exports = {
  rgb, rgba, blue, green, red
}
