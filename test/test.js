const crc = require('bindings')('cyclic_rc');
const assert = require('assert');

const values = [{
    value: "123456789",
    crc8: 0xA2,
    crc16: 0xBB3D,
    crc32: 0xCBF43926,
    crc64_ecma: 0x6C40DF5F0B497347,
    crc64_we: 0x62EC59E3F1A4F00A,
    crcdnp: 0x82EA,
    crcmodbus: 0x4B37,
    crcsick: 0x56A6,
    crcxmodem: 0x31C3,
    crc1d0f: 0xE5CC,
    crcffff: 0x29B1,
    crckermit: 0x8921
}, {
    value: "Lammert Bies",
    crc8: 0xA5,
    crc16: 0xB638,
    crc32: 0x43C04CA6,
    crc64_ecma: 0xF806F4F5C0F3257C,
    crc64_we: 0xFE25A9F50630F789,
    crcdnp: 0x4583,
    crcmodbus: 0xB45C,
    crcsick: 0x1108,
    crcxmodem: 0xCEC8,
    crc1d0f: 0x67A2,
    crcffff: 0x4A31,
    crckermit: 0xF80D
}, {
    value: "",
    crc8: 0x00,
    crc16: 0x0000,
    crc32: 0x00000000,
    crc64_ecma: 0x0000000000000000,
    crc64_we: 0x0000000000000000,
    crcdnp: 0xFFFF,
    crcmodbus: 0xFFFF,
    crcsick: 0x0000,
    crcxmodem: 0x0000,
    crc1d0f: 0x1D0F,
    crcffff: 0xFFFF,
    crckermit: 0x0000
}, {
    value: " ",
    crc8: 0x86,
    crc16: 0xD801,
    crc32: 0xE96CCF45,
    crc64_ecma: 0xCC7AF1FF21C30BDE,
    crc64_we: 0x568617D9EF46BE26,
    crcdnp: 0x50D6,
    crcmodbus: 0x98BE,
    crcsick: 0x2000,
    crcxmodem: 0x2462,
    crc1d0f: 0xE8FE,
    crcffff: 0xC592,
    crckermit: 0x0221
}];

for(let i = 0; i < values.length; i++) {
    let crc8 = crc.crc_8(values[i].value);
    let crc16 = crc.crc_16(values[i].value);
    let crc32 = crc.crc_32(values[i].value);
    let crc64_ecma = crc.crc_64_ecma(values[i].value);
    let crc64_we = crc.crc_64_we(values[i].value);
    let crcdnp = crc.crc_dnp(values[i].value);
    let crcmodbus = crc.crc_modbus(values[i].value);
    let crcsick = crc.crc_sick(values[i].value);
    let crcxmodem = crc.crc_xmodem(values[i].value);
    let crc1d0f = crc.crc_ccitt_1d0f(values[i].value);
    let crcffff = crc.crc_ccitt_ffff(values[i].value);
    let crckermit = crc.crc_kermit(values[i].value);

    assert(values[i].crc8 == crc8);
    assert(values[i].crc16 == crc16);
    assert(values[i].crc32 == crc32);
    assert(values[i].crc64_ecma == crc64_ecma);
    assert(values[i].crc64_we == crc64_we);
    assert(values[i].crcdnp == crcdnp);
    assert(values[i].crcmodbus == crcmodbus);
    assert(values[i].crcsick == crcsick);
    assert(values[i].crcxmodem == crcxmodem);
    assert(values[i].crc1d0f == crc1d0f);
    assert(values[i].crcffff == crcffff);
    assert(values[i].crckermit == crckermit);
}
