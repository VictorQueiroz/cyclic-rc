#include "node_crc.h"

#include <nan.h>
#include <crc/checksum.h>

bool GetArgument(v8::Local<v8::Value> arg, std::string& out) {
    if(!arg->IsString()) return false;
    auto length = Nan::DecodeBytes(arg);
    char buffer[length];
    Nan::DecodeWrite(buffer, length, arg);
    out = std::string(buffer,length);
    return true;
}

NAN_METHOD(Crc::Crc8) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }

    uint8_t result = crc_8(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc16) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_16(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc32) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint32_t result = crc_32(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc64_ECMA) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint64_t result = crc_64_ecma(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc64_WE) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint64_t result = crc_64_we(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc_DNP) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_dnp(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc_Modbus) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_modbus(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc_SICK) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_sick(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc_XModem) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_xmodem(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc_CCITT_1D0F) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_ccitt_1d0f(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc_CCITT_FFFF) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_ccitt_ffff(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

NAN_METHOD(Crc::Crc_Kermit) {
    std::string input;
    if(!GetArgument(info[0],input)) {
        Nan::ThrowError("First argument must be a valid string");
        return;
    }
    uint16_t result = crc_kermit(reinterpret_cast<const uint8_t*>(input.c_str()), input.length());

    info.GetReturnValue().Set(Nan::New<v8::Number>(result));
}

void Crc::Init(v8::Local<v8::Object> exports) {
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

NODE_MODULE(cyclic_rc, Crc::Init)
