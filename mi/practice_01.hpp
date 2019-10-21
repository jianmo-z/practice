/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_01.hpp
 * 时间: 9/11/2019-7:16 PM
 * 作者: Pip
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <bits/stdc++.h>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
输出左移后的矩阵
4
2 2 2 2
0 0 2 4
0 2 2 2
8 8 2 2

4
0 0 2 4
0 2 2 2
0 4 2 2
512 8 2 2
******************************开始写代码******************************/
bool is_zero(vector<int> &v, int i) {
    for (i = i + 1; i < v.size(); ++i) {
        if (v[i])
            return false;
    }
    return true;
}

void getMerge(string &str) {
    stringstream ss(str);
    string s;
    vector<int> v;
    while (getline(ss, s, ' ')) {
        v.push_back(stoi(s));
    }


    for (int i = 0; i < v.size() - 1;) {
        if (v[i] == v[i + 1] && v[i]) {
            v[i + 1] += v[i];
            v[i] = 0;
            v.erase(v.begin() + i);
            v.push_back(0);
        } else if (v[i] == 0 && is_zero(v, i)) {
            break;
        } else if (v[i] == 0) {
            v.erase(v.begin() + i);
            v.push_back(0);
            if (i)
                i = 0;
        } else {
            ++i;
        }
    }

    str.clear();
    // 数字转字符串
    char arr[6] = "";
    for (int j = 0; j < v.size(); ++j) {
        memset(arr, 0, sizeof(arr));
//        str += itoa(v[j], arr, 10);
        sprintf(arr, "%d", v[j]);
        str += arr;
        if (j + 1 != v.size())
            str += " ";
    }
}

string solution(vector<string> input) {
    string ret;
    for (int i = 0; i < input.size(); ++i) {
        getMerge(input[i]);
        ret += input[i];
        if (i + 1 != input.size())
            ret += "\n";
    }
    return ret;
}

/******************************结束写代码******************************/


int test() {
    string res;

    int _input_size = 0;
    cin >> _input_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    vector<string> _input;
    string _input_item;
    for (int _input_i = 0; _input_i < _input_size; _input_i++) {
        getline(cin, _input_item);
        _input.push_back(_input_item);
    }

    res = solution(_input);
    cout << res << endl;

    return 0;

}
