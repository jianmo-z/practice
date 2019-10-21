/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice.hpp
 * 时间: 9/12/2019-8:00 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

int test() {
    int m, n;
    cin >> m >> n;
    int tmp = 0;

    vector<vector<int>> Mymap(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            Mymap[i][j] = tmp;
        }
    }

    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == 0 && j == 0){
                dp[i][j] = Mymap[i][j];
                continue;
            }
            if (i == 0) {
                dp[i][j] = dp[i][j - 1] + Mymap[i][j];
                continue;
            }
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + Mymap[i][j];
                continue;
            }
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + Mymap[i][j];
        }
    }
    cout << dp.back().back();
    return 0;
}