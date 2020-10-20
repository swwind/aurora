var aurora = require('bindings')('aurora.node')

aurora.color = require('./src/color');

module.exports = aurora;
