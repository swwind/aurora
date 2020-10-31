function rgb(r, g, b) {
  return rgba(r, g, b, 0xff);
}
function rgba(r, g, b, a) {
  return { r: r & 0xff, g: g & 0xff, b: b & 0xff, a: a & 0xff };
}

module.exports = {
  rgb,
  rgba,
  blue: rgb(0, 0, 0xff),
  green: rgb(0, 0xff, 0),
  red: rgb(0xff, 0, 0),
  white: rgb(0xff, 0xff, 0xff),
  black: rgb(0, 0, 0),
}
