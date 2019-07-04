//
// Created by pip on 19-3-10.
//

/* 问题描述：
 * 给定一个数组和一个值，找出数组中那两个数之和等于该数
 * */

#include <bits/stdc++.h>

using namespace std;

int test_01() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << 1 + b - c;
    return 0;
}

int test_02() {
    int q;
    int sum = 0;
    bool tag = true;

    cin >> q;

    if (q <= 1) {
        cout << 0;
        return 0;
    }

    for (int i = 2; i <= q; ++i) {
        int tmp = sqrt(i);
        tag = true;

        for (int j = 2; j < tmp + 1; ++j) {
            if (i % j == 0) {
                tag = false;
                break;
            }
        }
        if (tag) { // 是素数
            for (int j = 1;; ++j) {
                if (pow(i, j) <= q) {
                    ++sum;
                } else {
                    break;
                }
            }

        }
    }
    cout << sum;
}

int test_03() {
    int n, r, it, sum = 1;
    cin >> n;
    if (n > 1) {
        sum = 2;
        for (int i = 2; i <= n; ++i) {
            it = i, r = 0;
            if (it & 1) {
                do {
                    if (it & 1) {
                        r |= 1;
                    }
                    if (it == r) {
                        ++sum;
                        break;
                    }
                    it = it >> 1;
                    if (it == r) {
                        ++sum;
                        break;
                    }
                    r = r << 1;
                } while (it);
            }
        }
    } else {
        sum = (n ? 2 : 1);
    }
    cout << sum;
    return 0;
}

void test() {
//    test_01();
//    test_02();
    test_03();
}