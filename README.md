# cyclic-rc

libcrc bindings for Node.JS, a very simple CRC library written completely in C.

## Installation

All you need is a valid C compiler installed in your computer

```
yarn add cyclic-rc
```

## Usage

All API methods matches the original C library. Check example bellow:

```
const crc = require('cyclic-rc');

const n = 'string';

let crc8 = crc.crc_8(n);
let crc16 = crc.crc_16(n);
let crc32 = crc.crc_32(n);
let crc64_ecma = crc.crc_64_ecma(n);
let crc64_we = crc.crc_64_we(n);
let crcdnp = crc.crc_dnp(n);
let crcmodbus = crc.crc_modbus(n);
let crcsick = crc.crc_sick(n);
let crcxmodem = crc.crc_xmodem(n);
let crc1d0f = crc.crc_ccitt_1d0f(n);
let crcffff = crc.crc_ccitt_ffff(n);
let crckermit = crc.crc_kermit(n);
```