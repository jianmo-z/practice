/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_38
 * 时间: 7/10/19-3:45 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        return dp(n);
    }

    string dp(int n) {
        string ret;
        if (n == 1) {
            ret = "1";
            return ret;
        }
        string str = dp(n - 1);

        int count = 0;
        char c;
        for (char it:str) {
            if(count == 0 || c == it) {
                ++count;
                c = it;
            }else {
                ret += static_cast<char>(count + '0');
                ret += c;
                count = 1;
                c = it;
            }
        }
        ret += static_cast<char>(count + '0');
        ret += c;
        return ret;
    }

};

void test() {
    Solution s;
    cout << s.countAndSay(5) << endl;
}