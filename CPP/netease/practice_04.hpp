/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_02.hpp
 * 时间: 9/7/2019-6:50 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

int getCount(vector<bool> &coffee) {
    int ret = 0;
    for (bool it :coffee) {
        if (it) ++ret;
    }
    return ret;
}

void dp(vector<bool> &coffee, int &k, int index, int &sum) {
    if (index >= 30) {
        return;
    }
    int step = 0;
    bool sign = false;
    // [1 .. step .. 1]
    for (int i = index + 1; i < 30; ++i) {
        if (coffee[i]) {
            sign = true;
            break;
        }
        ++step;
    }


    if (step > 2 * k) {
        coffee[index + k + 1] = true;
        sum += 1;
        index = index + k + 1;
    } else {
        if (sign) {
            index = index + step + 1;
        }
    }

    dp(coffee, k, index, sum);
}


int test() {
    int t = 0;  // 样例个数
    int k = 0;  // 最小间隔
    int m = 0;  // 固定喝咖啡的日子
    int day = 0;
    int sum = 0;

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> k >> m;
        vector<bool> coffee(30 + k + 1, false);
        for (int j = 0; j < m; ++j) {
            cin >> day;
            coffee[day + k] = true;
        }
        sum = m;
//      dp(coffee, k, 0, sum);
        for (int l = k + 1; l < coffee.size(); ++l) {
            if (coffee[l]) {
                continue;
            }
            bool add = true;
            for (int j = 1; j <= k; ++j) {
                if ((l - j >= 0) && coffee[l - j]) {
                    add = false;
                    break;
                } else if((l + j < coffee.size()) && coffee[l + j]) {
                    add = false;
                    break;
                }
            }
            if (add) {
                coffee[l] = true;
                ++sum;
            }
        }

        if (i + 1 == t) {
            cout << sum;
        } else {
            cout << sum << endl;
        }
    }
    return 0;
}

/*
4
0 10
1 2 3 4 5 6 7 8 9 10
1 15
1 3 5 7 9 11 13 15 17 19 21 23 25 27 29
1 7
5 9 13 17 21 25 29
1 0
 */