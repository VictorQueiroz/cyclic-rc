#include "node_crc.h"

#include <nan.h>
#include <crc/checksum.h>

using namespace v8;

bool CheckString(Local<Value> arg) {
    if(!arg->IsString()) {
        Nan::ThrowError("First argument must always be a string");
        return false;
    }
    return true;
}

NAN_METHOD(Crc::Crc8) {
    if(!CheckString(info[0])) {
        return;
    }

    Nan::Utf8String input(info[0]);

    uint8_t result = crc_8(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc16) {
    if(!CheckString(info[0])) {
        return;
    }
    Nan::Utf8String input(info[0]);
    uint16_t result = crc_16(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc32) {
    if(!CheckString(info[0])) {
        return;
    }

    Nan::Utf8String input(info[0]);
    uint32_t result = crc_32(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc64_ECMA) {
    if(!CheckString(info[0])) {
        return;
    }

    Nan::Utf8String input(info[0]);
    uint64_t result = crc_64_ecma(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc64_WE) {
    if(!CheckString(info[0])) return;

    Nan::Utf8String input(info[0]);
    uint64_t result = crc_64_we(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_DNP) {
    if(!CheckString(info[0])) {
        return;
    }

    Nan::Utf8String input(info[0]);
    uint16_t result = crc_dnp(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_Modbus) {
    if(!CheckString(info[0])) return;

    Nan::Utf8String input(info[0]);
    uint16_t result = crc_modbus(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_SICK) {
    if(!CheckString(info[0])) return;

    Nan::Utf8String input(info[0]);
    uint16_t result = crc_sick(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_XModem) {
    if(!CheckString(info[0])) return;

    Nan::Utf8String input(info[0]);
    uint16_t result = crc_xmodem(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_CCITT_1D0F) {
    if(!CheckString(info[0])) return;

    Nan::Utf8String input(info[0]);
    uint16_t result = crc_ccitt_1d0f(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_CCITT_FFFF) {
    if(!CheckString(info[0])) return;

    Nan::Utf8String input(info[0]);
    uint16_t result = crc_ccitt_ffff(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_Kermit) {
    if(!CheckString(info[0])) return;
    
    Nan::Utf8String input(info[0]);
    uint16_t result = crc_kermit(reinterpret_cast<uint8_t*>(*input), input.length());

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

void Crc::Init(Local<Object> exports) {
    Nan::SetMethod(exports, "crc_8", Crc8);
    Nan::SetMethod(exports, "crc_16", Crc16);
    Nan::SetMethod(exports, "crc_32", Crc32);
    Nan::SetMethod(exports, "crc_64_we", Crc64_WE);
    Nan::SetMethod(exports, "crc_64_ecma", Crc64_ECMA);
    Nan::SetMethod(exports, "crc_modbus", Crc_Modbus);
    Nan::SetMethod(exports, "crc_dnp", Crc_DNP);
    Nan::SetMethod(exports, "crc_sick", Crc_SICK);
    Nan::SetMethod(exports, "crc_xmodem", Crc_XModem);
    Nan::SetMethod(exports, "crc_ccitt_1d0f", Crc_CCITT_1D0F);
    Nan::SetMethod(exports, "crc_ccitt_ffff", Crc_CCITT_FFFF);
    Nan::SetMethod(exports, "crc_kermit", Crc_Kermit);
}

NODE_MODULE(cyclic_rc, Crc::Init);