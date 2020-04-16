/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_03.hpp
 * 时间: 2020/4/16-22:23
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

bool isContain(const vector<vector<int>> &v, int num) {
    if(v.empty()) return false;
    for (int i = v.size() - 1; i >= 0; ) {
        for (int j = 0; j < v[0].size() && i >= 0;) {
            if(v[i][j] == num) {
                return true;
            } else if(v[i][j] > num) {
                --i;
            } else {
                ++j;
            }

        }
    }
    return false;
}

int test() {
    vector<vector<int>> v = {{1, 2, 8,  9},
                             {2, 4, 9,  12},
                             {4, 7, 10, 13},
                             {6, 8, 11, 15}};
    assert(isContain(v, 5) == false);
    assert(isContain(v, 1) == true);
    assert(isContain(v, 15) == true);
    assert(isContain(v, 6) == true);
    assert(isContain(v, 9) == true);
    assert(isContain(v, -1) == false);
    return 0;
}