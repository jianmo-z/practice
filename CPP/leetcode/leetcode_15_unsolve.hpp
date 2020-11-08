//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    // 时间复杂度过高，超出leetcode的时间
    static vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ret;
        vector<int> it(3, 0);
        int m, n;

        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            m = 0, n = nums.size() - 1;

            // 进行夹逼查找
            for (;;) {
                if (m >= i || n <= i) { // 越界
                    break;
                }

                if (nums[m] + nums[n] + nums[i] == 0) { // 相等
                    it = vector<int>{nums[m], nums[i], nums[n]};
                    if (find(ret.begin(), ret.end(), it) == ret.end()) {
                        ret.push_back(it);
                    }
                    while(nums[m] == nums[m + 1] && m < n){
                        ++m;
                    }
                    while(nums[n] == nums[n - 1] && m < n) {
                        --n;
                    }
                    ++m, --n;
                } else if (nums[m] + nums[n] > -nums[i]) { // 大于n需要减一
                    --n;
                } else if (nums[m] + nums[n] < -nums[i]) { // 小于m需要加一
                    ++m;
                }


            }
        }
        return ret;
    }

};

void test() {
//    vector<int> v {-1, 0, 1, 2, -1, -4};
    vector<int> v{0, 0, 0, 0};
    Solution s;
    for (auto i : s.threeSum(v)) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}