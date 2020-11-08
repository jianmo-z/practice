/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice.hpp
 * 时间: 2019/8/31-17:49
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;


int test() {
    string str;
    vector<string> v;
    string tmp;
    bool con = true;

    cin >> str;

    // v = MySplit(str, ",\"");
    for (int i = 0; i < str.length(); ++i) {
        if(str[i] == ',') {
            v.push_back(move(tmp));
        } else {
            tmp += str[i];
        }
    }
    v.push_back(tmp);

    vector<string> ret;
    for (int j = 0; j < v.size() - 1; ++j) {
        if (v[j + 1][0] == '\"') {
            tmp += v[j];
        } else{

        }
    }
    return 0;
}