//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 二分查找
//    vector<int> searchRange_heap_overflow(vector<int> &nums, int target) {
//        vector<int> ret(2, -1);
//        int begin = 0, mid = nums.size() / 2, end = nums.size() - 1;
//
//        for (;;) {
//            if (begin >= end) {
//                break;
//            }
//            if(end - begin == 1){
//                if(nums[begin] == nums[end] && nums[begin] == target) {
//                    ret[0] = begin;
//                    ret[1] = end;
//                } else {
//                    if(nums[begin] == target) {
//                        ret[0] = ret[1] = begin;
//                    }else if(nums[end] == target){
//                        ret[0] = ret[1] = end;
//                    }
//                }
//                break;
//            }
//
//            if (nums[mid] > target) { // 大于
//                end = mid;
//                mid = (begin + end) / 2;
//            } else if (nums[mid] < target) { // 小于
//                begin = mid;
//                mid = (begin + end) / 2;
//            } else { // 等于，左右探测
//                begin = end = mid;
//                for (;;) {
//                    if (nums[begin] == target || nums[end] == target) {
//                        if (begin >= 0 && nums[begin] == target) {
//                            ret[0] = begin;
//                            --begin;
//                        }
//                        if (end <= nums.size() && nums[end] == target) {
//                            ret[1] = end;
//                            ++end;
//                        }
//                    } else {
//                        break;
//                    }
//                }
//                break;
//            }
//        }
//        return ret;
//    }

    // STL binary search
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> ret(2, -1);
        int begin = 0, mid = nums.size() / 2, end = nums.size() - 1;

        // 判断数据是否有效
        if(nums.size() == 0) {
            return ret;
        }

        // 找到位置
        for (;;) {
            if (begin == end) {
                break;
            }
            if (nums[begin] == target || nums[end] == target || nums[mid] == target) { // 等于，左右探测
                break;
            } else if (nums[mid] > target) { // 大于
                end = mid;
                mid = (begin + end) / 2;
            } else if (nums[mid] < target) { // 小于
                begin = mid;
                mid = (begin + end) / 2;
            }

            // 5 7 目标6死循环解决
            if(end - begin == 1) {
                break;
            }
        }
        if (nums[mid] == target) {
            begin = end = mid;
        } else if (nums[begin] == target) {
            end = begin;
        } else if (nums[end] == target) {
            begin = end;
        } else {
            return ret;
        }

        for (;;) {
            if ((begin >= 0 && nums[begin] == target) || (end <= nums.size() - 1 && nums[end] == target)) {
                if (begin >= 0 && nums[begin] == target) {
                    ret[0] = begin;
                    --begin;
                }
                if (end <= nums.size() - 1 && nums[end] == target) {
                    ret[1] = end;
                    ++end;
                }
            } else {
                break;
            }
        }

        return ret;
    }
};

void test() {
//    vector<int> nums{1, 2, 3, 5, 6, 6, 9, 10};
//    vector<int> nums{6, 6, 6, 6, 6, 6, 6, 6};
    vector<int> nums{5, 7, 7, 8, 8, 10};
//    vector<int> nums{1, 2, 2};

    int targe = 6;

    Solution s;
    auto ret = s.searchRange(nums, targe);
    cout << "[" << ret[0] << ", " << ret[1] << "]" << endl;
}