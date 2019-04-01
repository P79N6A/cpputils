/*************************************************************************
 * File:	byte_buffer.h
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	Mon 01 Apr 2019 03:03:39 PM CST
 ************************************************************************/

#ifndef _UTILS_BYTE_BUFFER_H_
#define _UTILS_BYTE_BUFFER_H_

#include <iostream>
#include <vector>
#include <map>
#include <stdint.h>
#include <stddef.h>
#include <string>
#include <unistd.h>
#include <memory.h>

using namespace std;

namespace cpputils{
    class ByteBuffer{
    private:
        vector <uint8_t> data;

        void growth(size_t l);

    public:
        //添加字节数据
        ByteBuffer &append(void *d, size_t len);

        ByteBuffer &appendInt(int d);

        ByteBuffer &appendInt8(int8_t d);

        ByteBuffer &appendInt16(int16_t d);

        ByteBuffer &appendInt32(int32_t d);

        ByteBuffer &appendInt64(int64_t d);

        ByteBuffer &appendUint(unsigned int d);

        ByteBuffer &appendUint8(uint8_t d);

        ByteBuffer &appendUint16(uint16_t d);

        ByteBuffer &appendUint32(uint32_t d);

        ByteBuffer &appendUint64(uint64_t d);

        ByteBuffer &appendSize(size_t d);

        ByteBuffer &appendBool(bool d);

        ByteBuffer &appendFloat(float d);

        ByteBuffer &appendDouble(double d);

        ByteBuffer &appendString(const string &d);

        //操作指定位置上的字节
        uint8_t &at(size_t pos);

        //转换方法
        int toInt();

        int8_t toInt8();

        int16_t toInt16();

        int32_t toInt32();

        int64_t toInt64();

        unsigned int toUint();

        uint8_t toUint8();

        uint16_t toUint16();

        uint32_t toUint32();

        uint64_t toUint64();

        size_t toSize();

        float toFloat();

        double toDouble();

        bool toBool();

        void toString(string &s);

        void rawData(void *buf, size_t len);

        size_t size();
    };
}
#endif
