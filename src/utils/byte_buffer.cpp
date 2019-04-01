/*************************************************************************
 * File:	byte_buffer.cpp
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	Mon 01 Apr 2019 03:03:45 PM CST
 ************************************************************************/

#include<iostream>
#include "byte_buffer.h"

using namespace std;

namespace cpputils{
    void ByteBuffer::growth(size_t l){
        if (this->data.size() < l){
            int i;
            for (i = 0; i < l; i++){
                this->data.push_back((uint8_t) '\0');
            }
        }
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
        return 0;
    }

    int8_t ByteBuffer::toInt8(){
        return 0;
    }

    int16_t ByteBuffer::toInt16(){
        return 0;
    }

    int32_t ByteBuffer::toInt32(){
        return 0;
    }

    int64_t ByteBuffer::toInt64(){
        int64_t d = 0;
        int i;
        uint8_t *tmp = (uint8_t * ) & d;
        for (i = 0; i < data.size() && i < sizeof(int64_t); i++){
            *(tmp + i) = data[i];
        }
        return d;
    }

    unsigned int ByteBuffer::toUint(){
        return 0;
    }

    uint8_t ByteBuffer::toUint8(){
        return 0;
    }

    uint16_t ByteBuffer::toUint16(){
        return 0;
    }

    uint32_t ByteBuffer::toUint32(){
        return 0;
    }

    uint64_t ByteBuffer::toUint64(){
        return 0;
    }

    size_t ByteBuffer::toSize(){
        return 0;
    }

    float ByteBuffer::toFloat(){
        return 0;
    }

    double ByteBuffer::toDouble(){
        return 0;
    }

    bool ByteBuffer::toBool(){
        return 0;
    }

    void ByteBuffer::toString(string &s){

    }

    void ByteBuffer::rawData(void *buf, size_t len){

    }

    size_t ByteBuffer::size(){
        return 0;
    }
}