/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_06.hpp
 * 时间: 2/13/2020-1:07 PM
 * 作者: Pip
 */
/**
3
1 2 3
4 5 6
7 8 9
2



4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
 */
#include <bits/stdc++.h>

using namespace std;

int test() {
    int n = 0;
    cin >> n;
    vector<vector<int>> v1(n, vector<int>(n, 0));
    vector<vector<int>> v2(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> v1[i][j];
        }
    }
    int times = 0;
    cin >> times;
    times %= 4;
    for (int k = 0; k < times; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                v2[j][n - 1 - i] = v1[i][j];
            }
        }
        v1 = v2;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v1[i][j];
            if (j + 1 != n)
                cout << " ";
        }
        if (i + 1 != n)
            cout << endl;
    }
    return 0;
}