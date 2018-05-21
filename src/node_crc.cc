#include <nan.h>
#include "node_crc.h"
#include <crc/checksum.h>

using namespace v8;

bool GetUnsignedString(Local<Value> arg, unsigned char** output_ptr, int* length_ptr) {
    if(!arg->IsString()) {
        Nan::ThrowError("first argument must be a string");
        return false;
    }

    Local<String> string = Local<String>::Cast(arg);
    *length_ptr = string->Utf8Length();
    int length = *length_ptr;
    char* buffer = (char*) calloc(1, length);
    string->WriteUtf8(buffer, length);

    *output_ptr = (unsigned char*) calloc(1, length);
    memcpy(*output_ptr, buffer, length);

    free(buffer);
    return true;
}

NAN_METHOD(Crc::Crc8) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint8_t result = crc_8(buffer, length);
    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc16) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_16(buffer, length);
    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc32) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint32_t result = crc_32(buffer, length);
    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc64_ECMA) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint64_t result = crc_64_ecma(buffer, length);
    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc64_WE) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint64_t result = crc_64_we(buffer, length);
    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_DNP) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_dnp(buffer, length);

    if(buffer != nullptr) {
        free(buffer);
    }

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_Modbus) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_modbus(buffer, length);

    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_SICK) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_sick(buffer, length);

    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_XModem) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_xmodem(buffer, length);

    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_CCITT_1D0F) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_ccitt_1d0f(buffer, length);

    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_CCITT_FFFF) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_ccitt_ffff(buffer, length);

    free(buffer);

    info.GetReturnValue().Set(Nan::New<Number>(result));
}

NAN_METHOD(Crc::Crc_Kermit) {
    unsigned char* buffer;
    int length;
    GetUnsignedString(info[0], &buffer, &length);

    uint16_t result = crc_kermit(buffer, length);

    free(buffer);

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