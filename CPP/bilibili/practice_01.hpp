/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_01.hpp
 * 时间: 9/10/2019-6:47 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

int test() {
    string str1, str2;
    cin >> str1 >> str2;
    int n1 = str1.length();
    int n2 = str2.length();
    int m = 0;
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
            }
        }
    }
    cout << (n1 > n2 ? n1 : n2) - dp.back().back();
    return 0;
}