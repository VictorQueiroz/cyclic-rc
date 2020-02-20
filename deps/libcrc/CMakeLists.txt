cmake_minimum_required(VERSION 2.4)
project(crc)

set(CRC_SOURCES src/crc16.c
            src/crc8.c
            src/crckrmit.c
            src/crc32.c
            src/crcccitt.c
            src/crcsick.c
            src/crc64.c
            src/crcdnp.c
            src/nmea-chk.c)
add_library(crc SHARED "${CRC_SOURCES}")
target_include_directories(crc PUBLIC include)