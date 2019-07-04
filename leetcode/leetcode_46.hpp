//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

/*
 * Given a collection of distinct integers, return all possible permutations.
 * Input: [1,2,3]
 *  Output:
 *  [
 *    [1,2,3],
 *    [1,3,2],
 *    [2,1,3],
 *    [2,3,1],
 *    [3,1,2],
 *    [3,2,1]
 *  ]
 *
 *  [[1,3,3,3],[1,3,3,3],[1,3,3,3],[1,3,3,3],[1,3,3,3],[1,3,3,3],[3,1,3,3],[3,1,3,3],[3,3,1,3],[3,3,3,1],[3,3,3,1],[3,3,1,3],[3,3,1,3],[3,3,3,1],[3,1,3,3],[3,1,3,3],[3,3,1,3],[3,3,3,1],[3,3,3,1],[3,3,1,3],[3,3,3,1],[3,3,1,3],[3,1,3,3],[3,1,3,3]]
 *  [[1,3,3,3],[1,3,3,3],[1,3,3,3],[1,3,3,3],[1,3,3,3],[1,3,3,3],[3,1,3,3],[3,1,3,3],[3,3,1,3],[3,3,3,1],[3,3,1,3],[3,3,3,1],[3,1,3,3],[3,1,3,3],[3,3,1,3],[3,3,3,1],[3,3,1,3],[3,3,3,1],[3,1,3,3],[3,1,3,3],[3,3,1,3],[3,3,3,1],[3,3,1,3],[3,3,3,1]]
 * */

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        long size = nums.size();

        long sum = 1;  // 总共有多少行,size的阶乘
        for (int i = 1; i < size + 1; ++i) {
            sum *= i;
        }

        vector<vector<int>> ret(0);
        sort(nums.begin(), nums.end());

        if(nums.size() >= 2){
            func(ret, nums, 0);
        }else{
            ret.push_back(nums);
        }

        return ret;
    }

    void func(vector<vector<int>> &ret ,vector<int> nums, int size) {

        // 剩下两个元素
        if (nums.size() - size == 2) {
            ret.push_back(nums);
//            if(nums[nums.size() - 1] != nums[nums.size() - 2]){
//                swap(nums[nums.size() - 1], nums[nums.size() - 2]);
//                ret.push_back(nums);
//            }

            swap(nums[nums.size() - 1], nums[nums.size() - 2]);
            ret.push_back(nums);
        } else {
            for (int i = size; i < nums.size(); ++i) {
                vector<int> tmp(nums);

//                if(tmp[size] != tmp[i] || size == i){
//                    swap(tmp[size], tmp[i]);
//                    func(ret, tmp, size + 1);
//                }

                if(size != i){
                    swap(tmp[size], tmp[i]);
                }
                func(ret, tmp, size + 1);
            }
        }

    }

};

void test() {
    vector<int> nums = {1, 3, 3};
    Solution s;
    auto ret = s.permute(nums);
    for(auto i : ret) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}