declare module "cyclic-rc" {
    export function crc_8(input: string): number;
    export function crc_16(input: string): number;
    export function crc_32(input: string): number;
    export function crc_64_we(input: string): number;
    export function crc_64_ecma(input: string): number;
    export function crc_modbus(input: string): number;
    export function crc_dnp(input: string): number;
    export function crc_sick(input: string): number;
    export function crc_xmodem(input: string): number;
    export function crc_ccitt_1d0f(input: string): number;
    export function crc_ccitt_ffff(input: string): number;
    export function crc_kermit(input: string): number;
}
