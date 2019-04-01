/*************************************************************************
 * File:	byte_buffer.cpp
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	Mon 01 Apr 2019 03:03:45 PM CST
 ************************************************************************/

#include<iostream>
#include "byte_buffer.h"

using namespace std;

namespace cpputils{
    ByteBuffer::ByteBuffer(){
        pos = 0;
    }

    //前置++
    ByteBuffer &ByteBuffer::operator++(){
        ++pos;
        return *this;
    }

    //后置++
    ByteBuffer &ByteBuffer::operator++(int n){
        pos++;
        return *this;
    }

    ByteBuffer &ByteBuffer::operator+=(size_t n){
        pos += n;
        return *this;
    }

    uint8_t &ByteBuffer::operator[](size_t p){
        return data[p];
    }

    //添加字节数据
    ByteBuffer &ByteBuffer::append(void *d, size_t len){
        size_t i;
        uint8_t *tmp = (uint8_t *) d;
        for (i = 0; i < len; i++){
            this->data.push_back(*(tmp + i));
        }
        return *this;
    }

    ByteBuffer &ByteBuffer::appendInt(int d){
        return append(&d, sizeof(int));
    }

    ByteBuffer &ByteBuffer::appendInt8(int8_t d){
        return append(&d, sizeof(int8_t));
    }

    ByteBuffer &ByteBuffer::appendInt16(int16_t d){
        return append(&d, sizeof(int16_t));
    }

    ByteBuffer &ByteBuffer::appendInt32(int32_t d){
        return append(&d, sizeof(int32_t));
    }

    ByteBuffer &ByteBuffer::appendInt64(int64_t d){
        return append(&d, sizeof(int64_t));
    }

    ByteBuffer &ByteBuffer::appendUint(unsigned int d){
        return append(&d, sizeof(unsigned int));
    }

    ByteBuffer &ByteBuffer::appendUint8(uint8_t d){
        return append(&d, sizeof(uint8_t));
    }

    ByteBuffer &ByteBuffer::appendUint16(uint16_t d){
        return append(&d, sizeof(uint16_t));
    }

    ByteBuffer &ByteBuffer::appendUint32(uint32_t d){
        return append(&d, sizeof(uint32_t));
    }

    ByteBuffer &ByteBuffer::appendUint64(uint64_t d){
        return append(&d, sizeof(uint64_t));
    }

    ByteBuffer &ByteBuffer::appendSize(size_t d){
        return append(&d, sizeof(size_t));
    }

    ByteBuffer &ByteBuffer::appendBool(bool d){
        return append(&d, sizeof(bool));
    }

    ByteBuffer &ByteBuffer::appendFloat(float d){
        return append(&d, sizeof(float));
    }

    ByteBuffer &ByteBuffer::appendDouble(double d){
        return append(&d, sizeof(double));
    }

    ByteBuffer &ByteBuffer::appendString(const string &d){
        size_t i;
        for (i = 0; i < d.size(); i++){
            this->data.push_back((uint8_t) d[i]);
        }
        return *this;
    }

    //操作指定位置上的字节
    uint8_t &ByteBuffer::at(size_t pos){
        return this->data[pos];
    }

    //转换方法
    int ByteBuffer::toInt(){
        int d = 0;
        rawData(&d, sizeof(int));
        return d;
    }

    int8_t ByteBuffer::toInt8(){
        int8_t d = 0;
        rawData(&d, sizeof(int8_t));
        return d;
    }

    int16_t ByteBuffer::toInt16(){
        int16_t d = 0;
        rawData(&d, sizeof(int16_t));
        return d;
    }

    int32_t ByteBuffer::toInt32(){
        int32_t d = 0;
        rawData(&d, sizeof(int32_t));
        return d;
    }

    int64_t ByteBuffer::toInt64(){
        int64_t d = 0;
        rawData(&d, sizeof(int64_t));
        return d;
    }

    unsigned int ByteBuffer::toUint(){
        unsigned int d = 0;
        rawData(&d, sizeof(unsigned int));
        return d;
    }

    uint8_t ByteBuffer::toUint8(){
        uint8_t d = 0;
        rawData(&d, sizeof(uint8_t));
        return d;
    }

    uint16_t ByteBuffer::toUint16(){
        uint16_t d = 0;
        rawData(&d, sizeof(uint16_t));
        return d;
    }

    uint32_t ByteBuffer::toUint32(){
        uint32_t d = 0;
        rawData(&d, sizeof(uint32_t));
        return d;
    }

    uint64_t ByteBuffer::toUint64(){
        uint64_t d = 0;
        rawData(&d, sizeof(uint64_t));
        return d;
    }

    size_t ByteBuffer::toSize(){
        size_t d = 0;
        rawData(&d, sizeof(size_t));
        return d;
    }

    float ByteBuffer::toFloat(){
        float d = 0;
        rawData(&d, sizeof(float));
        return d;
    }

    double ByteBuffer::toDouble(){
        double d = 0;
        rawData(&d, sizeof(double));
        return d;
    }

    bool ByteBuffer::toBool(){
        bool d = false;
        rawData(&d, sizeof(bool));
        return d;
    }

    void ByteBuffer::toString(string &s, size_t len){
        size_t cpos = pos;
        if (len < 0){
            len = data.size() - cpos;
        }
        int i;
        for (i = cpos; i < data.size() && i < cpos + len; i++){
            s.append((char *) &data[i]);
        }
    }

    void ByteBuffer::rawData(void *buf, size_t len){
        int i;
        uint8_t *tmp = (uint8_t *) buf;
        size_t cpos = pos;
        for (i = cpos; i < data.size() && i < cpos + len; i++){
            *(tmp + i) = data[i];
        }
    }

    size_t ByteBuffer::size(){
        return data.size();
    }
}