const Benchmark = require('benchmark');
 
const crc = require('../index');
const pyCRC = require('crc');

const crypto = require('crypto');
const bigString = crypto.randomBytes(0xffff).toString('hex');

// add tests
new Benchmark.Suite().add('pyCRC#crc32', function() {
  pyCRC.crc32(bigString);
})
.add('crc#crc32', function() {
  crc.crc_32(bigString);
})
// add listeners
.on('cycle', function(event) {
  console.log(String(event.target));
})
.on('complete', function() {
  console.log('Fastest is ' + this.filter('fastest').map('name'));
})
// run async
.run({ 'async': true });

// add tests
new Benchmark.Suite().add('pyCRC#crc32', function() {
  pyCRC.crc32(bigString);
})
.add('pyCRC#crc8', function() {
  pyCRC.crc8(bigString);
})
.add('crc#crc8', function() {
  crc.crc_8(bigString);
})
// add listeners
.on('cycle', function(event) {
  console.log(String(event.target));
})
.on('complete', function() {
  console.log('Fastest is ' + this.filter('fastest').map('name'));
})
// run async
.run({ 'async': true });

new Benchmark.Suite().add('pyCRC#crc16', function() {
  pyCRC.crc16(bigString);
})
.add('crc#crc16', function() {
  crc.crc_16(bigString);
})
// add listeners
.on('cycle', function(event) {
  console.log(String(event.target));
})
.on('complete', function() {
  console.log('Fastest is ' + this.filter('fastest').map('name'));
})
// run async
.run({ 'async': true });