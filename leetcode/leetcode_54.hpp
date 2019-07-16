/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_54.hpp
 * 时间: 7/16/19-10:18 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Input:
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 *
 * Output: [1,2,3,6,9,8,7,4,5]
 *
 * */
 /// 参考链接：https://blog.csdn.net/zrh_csdn/article/details/80467032
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.empty()) {
            return ret;
        } else if(matrix.size() == 1){
            for(int i : matrix[0]) {
                ret.push_back(i);
            }
            return ret;
        }

        /// Row：行
        /// Column：列
        int sum = matrix.size() * matrix[0].size();
        int beginRow = 0;
        int endRow = matrix.size() - 1;
        int beginColumn = 0;
        int endColumn = matrix[0].size() - 1;
        int begin = 0, end = 0;
        while (sum != ret.size()) {
            /// 最上一层，从左至右遍历
            for(begin = beginColumn, end = endColumn; begin <= end; ++begin) {
                ret.push_back(matrix[beginRow][begin]);
            }
            ++beginRow;  /// 下移
            if(beginRow > endRow) {
                break;
            }

            /// 最右一列，从上至下遍历
            for(begin = beginRow, end = endRow; begin <= end; ++begin) {
                ret.push_back(matrix[begin][endColumn]);
            }
            --endColumn;
            if(endColumn < beginColumn) {
                break;
            }

            /// 最下一层，从右至左遍历
            for(begin = endColumn, end = beginColumn; begin >= end; --begin) {
                ret.push_back(matrix[endRow][begin]);
            }
            --endRow;
            if(endRow < beginRow) {
                break;
            }

            /// 最左一列，从下至上遍历
            for(begin = endRow, end = beginRow; begin >= end; --begin) {
                ret.push_back(matrix[begin][beginColumn]);
            }
            ++beginColumn;
            if(beginColumn > endColumn) {
                break;
            }
        }
        return ret;
    }
};

void test() {
    vector<vector<int>> matrix{
                {2, 3, 4},
                {5, 6, 7},
                {8, 9, 10},
                {11,12,13},
                {14,15,16},
            };
    Solution s;
    for(int i : s.spiralOrder(matrix)) {
        cout << i << " ";
    }
    cout << endl;
}