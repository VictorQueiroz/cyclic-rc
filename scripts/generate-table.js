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

let compiler = '';
if(os.platform() === 'linux' || os.platform() === 'darwin') {
    compiler = 'cc';
} else if(os.platform() === 'win32') {
    compiler = 'cl';
} else {
    throw new Error(`Could not find compiler for platform ${os.platform()}`);
}

let outputFlag;
if(os.platform() === 'linux' || os.platform() === 'darwin') {
    outputFlag = '-o';
} else if(os.platform() === 'win32') {
    outputFlag = '-Fo';
}

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