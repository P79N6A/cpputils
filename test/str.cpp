/*************************************************************************
 * File:	test.cpp
 * Author:	liuyongshuai<liuyongshuai@hotmail.com>
 * Time:	2019年03月21日 星期四 17时08分17秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include "../src/utils/strutils.h"
#include "../src/utils/md5.h"
#include "../src/utils/color.h"
#include "../src/utils/byte_buffer.h"
#include "../src/utils/some.h"
#include "../src/utils/regexp.h"
#include "../src/utils/rune_utils.h"
#include "../src/client/http_client_utils.h"

using namespace std;

void printVector1(const std::vector <string> &output){
    vector< string >::const_iterator iter;
    cout << endl;
    cout << endl;
    for (iter = output.begin(); iter != output.end(); iter++){
        cout << *iter << endl;
    }
    cout << endl;
    cout << endl;
}

void printMap1(const std::map <string, string> &output){
    map< string, string >::const_iterator iter;
    cout << endl;
    cout << endl;
    for (iter = output.begin(); iter != output.end(); iter++){
        cout << "k=" << iter->first << "\tv=" << iter->second << endl;
    }
    cout << endl;
    cout << endl;
}

int main(){
    string s = "C/C++语言提供了几个标准库函数，可以将字符串转换为任意类型(整型、长整型、浮点型等)。";
    vector <int32_t> unicodes;
    cpputils::StrUtils::utf8ToUnicode(s, unicodes);
    vector< int32_t >::iterator iter;

    for (iter = unicodes.begin(); iter != unicodes.end(); iter++){
        cout << *iter << "\t";
    }
    cout << endl;

    //再转回来
    string str;
    cpputils::StrUtils::unicodesToUTF8(unicodes, str);
    cout << str << endl;

    //计算md5
    char buf[33] = {0};
    cpputils::MD5 md5;
    md5.MD5Str(s.c_str(), s.size(), buf, 33);
    cout << buf << endl;

    string rawStr = "各地区、各部门要抓紧做好本地区、本领域的劳动节假期调整落实工作，采取有效措施，保障交通运力，加强旅游服务，丰富产品供给，强化综合调控，确保平稳运行。";
    string b64en;
    string b64de;
    cpputils::StrUtils::base64Encode(rawStr, b64en);
    cpputils::StrUtils::base64Decode(b64en, b64de);
    cout << rawStr << endl;
    cout << b64en << endl;
    cout << b64de << endl;

    string rawUrl = "http://wiki.intra.xiaojukeji.com/pages/viewpage.action?pageId=114204118#id-4.计价&收银服务-术语说明";
    string urlEn;
    string urlDe;
    cpputils::StrUtils::urlEncode(rawUrl, urlEn);
    cpputils::StrUtils::urlDecode(urlEn, urlDe);
    cout << rawUrl << endl;
    cout << urlEn << endl;
    cout << urlDe << endl;

    string out1;
    string out2;
    cpputils::Color::Green(rawStr, 1, 1, out1);
    cpputils::Color::Yellow(rawStr, 0, 0, out2);
    cout << out1 << endl;
    cout << out2 << endl;

    size_t screenWidth, screenHeight;
    cpputils::SomeUtils::getTerminalSize(&screenWidth, &screenHeight);
    cout << screenWidth << "\t" << screenHeight << endl;

    string trimSp1 = "  c\n\t   ";
    cpputils::StrUtils::trimSpace(trimSp1);
    cout << "trimSp=" << trimSp1 << "\tsize=" << trimSp1.size() << endl;
    string trimSp2 = "  c\n\t   ";
    cpputils::StrUtils::trimLeftSpace(trimSp2);
    cout << "trimSp2=" << trimSp2 << "\tsize=" << trimSp2.size() << endl;
    string trimSp3 = "  c\n\t   ";
    cpputils::StrUtils::trimRightSpace(trimSp3);
    cout << "trimSp3=" << trimSp3 << "\tsize=" << trimSp3.size() << endl;

    string trimCH1 = "abcaaaaaaa";
    cpputils::StrUtils::trimChar(trimCH1, 'a');
    cout << "trimCH1=" << trimCH1 << "\tsize=" << trimCH1.size() << endl;

    cpputils::RegExp reg1(";");
    string ck = "a=c;d=f;a=adsfadfadfadfadfadf;d=453453453534;;;;;;;;-";
    vector <string> reg1SubList;
    reg1.reg_split(ck, reg1SubList);
    printVector1(reg1SubList);

    cout << "-------cpputils::StrUtils::strSplit-------" << endl;
    vector <string> split2SubList;
    cpputils::StrUtils::strSplit(ck, ';', split2SubList);
    printVector1(split2SubList);
    cout << endl;

    cout << "-------cpputils::HttpClientUtils::splitRawCookie-------" << endl;
    map <string, string> cookie2SubList;
    cpputils::HttpClientUtils::splitRawCookie(ck, cookie2SubList);
    printMap1(cookie2SubList);
    string ck1;
    cpputils::HttpClientUtils::joinRawCookie(cookie2SubList, ck1);
    cout << ck1 << endl;
    cout << endl;

    cout << "---------/dev/urandom---------" << endl;
    string deviceRandom1;
    cpputils::SomeUtils::getDeviceRandom(deviceRandom1, 30);
    cout << deviceRandom1 << endl;
    cout << endl;

    cout << "---------local ip---------" << endl;
    vector <uint32_t> ipList;
    cpputils::SomeUtils::getLocalIP(ipList);
    cout << endl;

    cout << "---------clock---------" << endl;
    uint64_t ms, ns;
    cpputils::SomeUtils::getMicroSeconds(ms);
    cpputils::SomeUtils::getNanoSeconds(ns);
    cout << "ms=" << ms << "\tns=" << ns << endl;
    cout << endl;

    cout << "---------random---------" << endl;
    int i;
    for (i = 0; i < 10; i++){
        int r = cpputils::SomeUtils::getRandom();
        cout << "random int=" << r << endl;
    }
    cout << endl;

    cout << "---------userAgent---------" << endl;
    string ua;
    for (i = 0; i < 10; i++){
        cpputils::HttpClientUtils::genRandomUserAgent(ua);
        cout << "User-Agent=" << ua << endl;
        ua.clear();
    }
    cout << endl;

    cout << "---------isFileExists---------" << endl;
    const char *fs[] = {
            "./str.cpp",
            "./abc",
            "/dev",
            "wendao",
    };
    size_t fsLen = sizeof(fs) / sizeof(char *);
    for (i = 0; i < fsLen; i++){
        const char *f = fs[i];
        bool r = cpputils::SomeUtils::isFileExist(f);
        cout << "file[" << f << "] isExist:" << r << endl;
        string bname;
        cpputils::SomeUtils::fileBaseName(f, bname);
        cout << "file[" << f << "] basename:" << bname << endl;
    }
    cout << endl;

    cout << "---------fileSize & getContent---------" << endl;
    string tmpFilePath = "/Users/liuyongshuai/Documents/service.conf";
    size_t fileSize = cpputils::SomeUtils::fileSize(tmpFilePath);
    cout << "fileSize=" << fileSize << endl;
    char *tmpFileBuf = (char *) malloc(sizeof(char) * fileSize + 1);
    bzero(tmpFileBuf, sizeof(char) * fileSize + 1);
    cpputils::SomeUtils::getFileContent(tmpFilePath, tmpFileBuf);
    cout << "getFileContent=" << endl;
    //cout << tmpFileBuf << endl;

    cout << "---------byte_buffer---------" << endl;
    cpputils::ByteBuffer bb;
    bb.appendInt(12345);
    int64_t r = bb.toInt64();
    cout << r << endl;
};
