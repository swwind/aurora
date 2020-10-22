function rgb(r, g, b) {
  return { r, g, b, a: 0xff };
}
function rgba(r, g, b, a) {
  return { r, g, b, a };
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
