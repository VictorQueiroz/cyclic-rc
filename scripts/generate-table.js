/**
 * This file is used to create gentab32.inc and 
 * gentab64.inc tab files located in deps/libcrc/tab 
 * folder
 */

const os = require('os');
const fs = require('fs');
const { spawnSync: spawn, execFileSync: execFile } = require('child_process');

const files = [
    __dirname + '/../deps/libcrc/precalc/precalc.c',
    __dirname + '/../deps/libcrc/precalc/crc32_table.c',
    __dirname + '/../deps/libcrc/precalc/crc64_table.c'
];

const buildDirectory = __dirname + '/../build';

if(!fs.existsSync(buildDirectory))
    fs.mkdirSync(buildDirectory);

const compiler = os.platform() == 'linux' ? 'cc' : 'cl';
const outputFlag = os.platform() == 'linux' ? '-o' : '-Fo';

spawn(compiler, [
    ...files,
    '-I', `${__dirname}/../deps/libcrc/include`,
    outputFlag, `${__dirname}/../build/precalc`
], {
    detached: true,
    stdio: "inherit"
});

execFile(__dirname + '/../build/precalc', [
    '--crc32', __dirname + '/../deps/libcrc/tab/gentab32.inc',
], {
    detached: true,
    stdio: "inherit"
});

spawn(__dirname + '/../build/precalc', [
    '--crc64', __dirname + '/../deps/libcrc/tab/gentab64.inc',
], {
    detached: true,
    stdio: "inherit"
});