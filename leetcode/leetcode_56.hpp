/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_56
<<<<<<< Updated upstream
 * 时间: 2019/7/30-15:23
 * 作者: zhanghui05
=======
 * 时间: 7/25/19-9:18 PM
 * 作者: pip
>>>>>>> Stashed changes
 */

#include <bits/stdc++.h>

using namespace std;
<<<<<<< Updated upstream
/**
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
 */

class Solution {
public:
    /**
    * 四种情况
    * int a1 = 0, a2 = 0;
    * int b1 = 0, b2 = 0;
    * a1     a2   b1     b2
    * ┗━━━━━━┛    ┗━━━━━━┛
    * ******************************
    * 1、情况一：
    * a1     a2
    * ┗━━━━━━┛
    *           b1     b2
    *           ┗━━━━━━┛
    * ******************************
    * 2、情况二：
    * a1       a2
    * ┗━━━━━━━━┛
    *       b1       b2
    *       ┗━━━━━━━━┛
    * ******************************
    * 3、情况三/四：
    * a1               a2        a1         a2
    * ┗━━━━━━━━━━━━━━━━┛          ┗━━━━━━━━┛
    *     b1       b2         b1              b2
    *     ┗━━━━━━━━┛          ┗━━━━━━━━━━━━━━━━┛
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if(intervals.size() < 2) {
            return intervals;
        }

        int a1 = intervals[0][0], a2 = intervals[0][1];
        int b1 = intervals[1][0], b2 = intervals[1][1];

        for(int i = 2; i < intervals.size(); ++i) {
            if(a2 < b1) {  // 情况一: a1 < a2 < b1 < b2
                ret.emplace_back(vector<int>(a1, a2));
                a1 = b1;
                a2 = b2;
            } else if(b1 <= a2 && a1 <= b1) {  // 情况二：a1 < b1 <= a2 < b2
                a2 = b2;
            } else {  // 情况三/四: a1 < b1 < b2 < a2 或 b1 < a1 < a2 < b2
                a1 = a1 > b1 ? a1 : b1;
                a2 = a2 > b2 ? a2 : b2;
            }
            b1 = intervals[i][0];
            b2 = intervals[i][1];
        }
        return ret;
    }
=======

class Solution {
public:

>>>>>>> Stashed changes

};

void test() {
<<<<<<< Updated upstream
    vector<vector<int>> intervals;
    vector<int> v1 {1, 3};
    vector<int> v2 {2, 6};
    vector<int> v3 {8, 10};
    vector<int> v4 {15, 18};
    intervals.push_back(v1);
    intervals.push_back(v2);
    intervals.push_back(v3);
    intervals.push_back(v4);

    Solution s;
    auto ans = s.merge(intervals);
    for(auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

=======
    Solution s;
    cout << "hello world" << endl;
>>>>>>> Stashed changes
}