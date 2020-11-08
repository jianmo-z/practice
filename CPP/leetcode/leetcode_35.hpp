//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int ret = 0;
        for (int &it :nums) {
            if (it >= target) {
                break;
            }
            ++ret;
        }
        return ret;
    }

};

void test() {
    vector<int> nums{1, 3, 3, 5};
    int targe = 3;
    Solution s;
    cout << s.searchInsert(nums, targe) << endl;
}