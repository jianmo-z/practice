//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int i) {
//    return i >= 662351799;
    return i >= 4;
}

class Solution {
public:
    // 二分查找
    int firstBadVersion(int n) {
        int begin = 0, mid = n / 2, end = n;
        for (;;) {
            if (begin == end) {
                break;
            }
            if (isBadVersion(mid)) {
                if (!isBadVersion(mid - 1)) {
                    return mid;
                } else {
                    end = mid;
                    mid = (begin / 2 + end / 2) + ((begin & end & 1) ? 1 : 0);
                }
            } else {
                if (isBadVersion(mid + 1)) {
                    return mid + 1;
                } else {
                    begin = mid;
                    mid = (begin / 2 + end / 2) + ((begin & end & 1) ? 1 : 0);
                }
            }
        }
        return mid;
    }

};

void test() {
    Solution s;
//    cout << s.firstBadVersion(1182691386) << endl;
    cout << s.firstBadVersion(5) << endl;
}