import Benchmark from 'benchmark'; 
import crc from '../index';
import * as pyCRC from 'crc';
import {randomBytes} from 'crypto';

const bigString = randomBytes(0xFFFFFF).toString('hex');

const methods: [
    ['crc32', 'crc_32'],
    ['crc8', 'crc_8'],
    ['crc16', 'crc_16'],
    ['crc16kermit', 'crc_kermit']
] = [
    ['crc32', 'crc_32'],
    ['crc8', 'crc_8'],
    ['crc16', 'crc_16'],
    ['crc16kermit', 'crc_kermit']
];

for(const m of methods) {

    // add tests
    new Benchmark.Suite()
    .add(`crc.${m[0]}`, function() {
        crc[m[1]](bigString);
    })
    .add(`pyCRC.${m[0]}`, function() {
        pyCRC[m[0]](bigString);
    })
    // add listeners
    .on('cycle', function(event: {target: any;}) {
        console.log(String(event.target));
    })
    .on('complete', function(this: Benchmark.Suite) {
        console.log('Fastest is ' + this.filter('fastest').map((name: string) => name));
    })
    // run async
    .run({ 'async': true });
  
}
