/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_48
 * 时间: 7/8/19-10:34 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;
/**
 *
 * You are given an n x n 2D matrix representing an image.
 * Rotate the image by 90 degrees (clockwise).
 *
 * Note:
 *      You have to rotate the image in-place, which means you
 *  have to modify the input 2D matrix directly. DO NOT alloc-
 *  ate another 2D matrix and do the rotation.
 *
 * Example 1:
 *
 *   Given input matrix =
 *   [
 *     [1,2,3],
 *     [4,5,6],
 *     [7,8,9]
 *   ],
 *
 *   rotate the input matrix in-place such that it becomes:
 *   [
 *     [7,4,1],
 *     [8,5,2],
 *     [9,6,3]
 *   ]
 * */

class Solution {
public:
    // 1.x,y <=> y,x
    // 2.再做关于y轴对称
    void rotate(vector<vector<int>>& matrix) {
        int x = 0, y = 0;
        int sum = matrix.size() * matrix.size();
        int weight = matrix.size();
        for(int i = 0; i * 2 < sum; ++i) {

        }
    }

};

void test() {
    vector<vector<int>> matirx{
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Solution s;
    s.rotate(matirx);
    for(auto i:matirx) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}