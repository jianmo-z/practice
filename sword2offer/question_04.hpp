/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: question_04.hpp
 * 时间: 2020/4/17-10:24
 * 作者: Pip
 */

#include <bits/stdc++.h>
#include "gtest/gtest.h"

using namespace std;

/**
 * 空格替换为%20
 * @param str 要替换的字符串
 * @return 替换后的字符串
 */
string replackBlank01(const string& str) {
    string ret;
    int numOfBlank = 0;

    // 计算有多少个空格
    for_each(str.begin(), str.end(), [&numOfBlank](const char c) { if (c == ' ')++numOfBlank; });

    // 分配内存空间
    ret.resize(0);
    ret.reserve(str.size() + numOfBlank * 2 + 1);

    // 字符串进行替换
    for_each(str.begin(), str.end(), [&ret](const char c) { c == ' ' ? ret.append("%20") : ret += c; });

    return ret;
}

string replackBlank02(string str) {

    int numOfBlank = 0;

    // 计算有多少个空格
    for_each(str.begin(), str.end(), [&numOfBlank](const char c) { if (c == ' ')++numOfBlank; });



    // 字符串进行替换
    int j = str.size() + numOfBlank * 2;
    int i = str.size() - 1;

    // 分配内存空间
    str.resize(str.size() + numOfBlank * 2 + 1);
    for (; i >= 0; --i) {
        if(str.at(i) == ' ') {
            str.at(--j) = '0';
            str.at(--j) = '2';
            str.at(--j) = '%';
        } else {
            str.at(--j) = str.at(i);
        }
    }

    return str;
}


TEST(question_04, replackBlank01) {
    EXPECT_STREQ(replackBlank01(" hello world ").data(), "%20hello%20world%20");
    EXPECT_STREQ(replackBlank01("").data(), "");
    EXPECT_STREQ(replackBlank01("   ").data(), "%20%20%20");
}

TEST(question_04, replackBlank02) {
    EXPECT_STREQ(replackBlank02(" hello world ").data(), "%20hello%20world%20");
    EXPECT_STREQ(replackBlank02("").data(), "");
    EXPECT_STREQ(replackBlank02("   ").data(), "%20%20%20");
}