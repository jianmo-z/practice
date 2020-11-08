//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

/*
#include <bits/stdc++.h>

using namespace std;

int main() {

}
*/
int getDay(int year, int n) {
    //              1   2  3   4   5    6   7   8   9  10  11  12
    int month[] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int ret = 0;
    if (n != 1) { // 不是二月直接返回
        ret = month[n];
    } else { // 判断闰年和平年
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                ret = 29;
            } else {
                ret = 28;
            }
        } else {
            ret = 28;
        }
    }
    return ret;
}

int test_01() {
    int n = 0;
    int year, day, times = 0;
    vector<int> ans;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        year = 0, day = 0;
        cin >> year >> day;
        times = 0;
        for (int j = 0; j < 12; ++j) {
            int tmp = getDay(year, j);
            // cout << tmp << " ";
            if (day < tmp) {
                ++times;
            }
        }
        ans.push_back(times);
    }
    for (int i = 0; i < ans.size(); ++i) {

        if (i == ans.size() - 1) {
            cout << ans[i] << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
    // 7
    return 0;
}

int dp(int m, int a1, int h1, int a2, int b2, int h2, int c1, int c2) {
    // 当城堡血量小于等于0退出
    if(h1 <= 0) {
        return h1;
    }

    // 城堡攻击力大于商人血量+防御 需要升级防御，没钱失败升级
    if (a1 >= h2 + b2) {
        if(m - (a1 - h2 - b2) * c2 > 0) {
            m = m - (a1 - h2 - b2) * c2;
        } else {
            return h1;
        }
    }
//    // 商人防御小于攻击时,至少升级的防御力
//    if(b2 < a1) {
//        h2 -= (a1 - b2);
//    }

    // 商人攻击城堡
    h1 -= a2;


    return dp(m, a1, h1, a2, b2, h2, c1, c2);
}

int test_02() {
    int n;
    int m, a1, h1, a2, b2, h2, c1, c2, c;
    cin >> n;

    /*
     *  钻石 m
     *  城堡：
     *      攻击力：a1
     *      血量：h1
     *      防御力：0
     *  商人：
     *      攻击力：a2
     *      血量：h2
     *      防御力：b2
     *      升级攻击力：c1
     *      升级防御力：c2
     *      购买投石车：c
     * */

    for (int i = 0; i < n; ++i) {
        cin >> m >> a1 >> h1 >> a2 >> b2 >> h2 >> c1 >> c2 >> c;
        m -= c;
        cout << h1 - dp(m, a1, h1, a2, b2, h2, c1, c2);
    }
    return 0;
}

void test() {
    test_01();
//    test_02();
}