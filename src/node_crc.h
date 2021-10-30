#ifndef NODE_CRC_H_
#define NODE_CRC_H_

#include <nan.h>

class Crc {
private:
    static NAN_METHOD(Crc8);
    static NAN_METHOD(Crc16);
    static NAN_METHOD(Crc32);
    static NAN_METHOD(Crc64_ECMA);
    static NAN_METHOD(Crc64_WE);
    static NAN_METHOD(Crc_DNP);
    static NAN_METHOD(Crc_Modbus);
    static NAN_METHOD(Crc_SICK);
    static NAN_METHOD(Crc_XModem);
    static NAN_METHOD(Crc_CCITT_1D0F);
    static NAN_METHOD(Crc_CCITT_FFFF);
    static NAN_METHOD(Crc_Kermit);
public:
    static void Init(v8::Local<v8::Object> exports);
};

#endif