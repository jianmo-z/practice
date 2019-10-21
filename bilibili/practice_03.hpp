/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_01.hpp
 * 时间: 9/10/2019-6:47 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split(string str, string item) {
    string mystr = str;
    string myitem = item;
    vector<string> ret;
    unsigned int pos = 0;
    while (1) {
        unsigned int p = mystr.find(item.c_str(), pos);
        string tmp = mystr.substr(pos, p - pos);
        ret.push_back(tmp);
        pos = p + 1;
        if (p == string::npos) {
            break;
        }
    }
    return ret;
}

int test() {
    string str1;
    string str2;
    string str3;
    cin >> str1 >> str2 >> str3;
    vector<string> ans = split(str3, str1);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        vector<string> tmp = split(ans[i], str2);
        cout<< tmp[0] << " " << tmp[1];
        if (i + 1 != ans.size())
            cout <<endl;
    }

//    vector<string> ans;
//    vector<string> ret;
//    stringstream ss(str3);
//    string tmp;
//    while (getline(ss, tmp, str1)) {
//        ans.push_back(tmp);
//    }
//    cout << ans.size() << endl;
//    for (int i = 0; i < ans.size(); ++i) {
//        int pos = ans[i].find(str2);
//        if(pos == 0 || pos == string::npos)
//            continue;
//        cout << string(ans[i].begin(), ans[i].begin() + pos) << " " << string(ans[i].begin() + pos + 1, ans[i].end());
//        if (i + 1 != ans.size())
//            cout << endl;
//    }

    return 0;
}