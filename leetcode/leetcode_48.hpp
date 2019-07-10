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

    // 方法一
    void rotate(vector<vector<int>>& matrix) {
        int x1 = 0, y1 = 0;
        int x2 = 0, y2 = 0;
        int weight = matrix.size();

/// 矩阵一
// {1,2,3}
// {4,5,6}
// {7,8,9}
        for (int i = 0; i < weight; ++i) {
            for(int j = 0; j < i; ++j) {
                x1 = weight - i - 1;
                y1 = j;
                x2 = weight - 1 - y1;
                y2 = weight - 1 - x1;
                swap(matrix[x1][y1], matrix[x2][y2]);
            }
        }
/// 矩阵二
//{9,6,3}
//{8,5,2}
//{7,4,1}
        for(int i = 0; i < weight/ 2; ++i) {
            swap(matrix[i], matrix[weight - 1 -i]);
        }

/// 矩阵三
//{7,4,1}
//{8,5,2}
//{9,6,3}
    }


    // 方法二
    void rotate2(vector<vector<int>>& matrix) {
        int weight = matrix.size();

        for (int i = 0; i < weight / 2; ++i) {
            swap(matrix[i], matrix[weight - 1 -i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }

        for(int i = 0; i < weight; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
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
    s.rotate2(matirx);
    for(auto i:matirx) {
        for(auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }
}