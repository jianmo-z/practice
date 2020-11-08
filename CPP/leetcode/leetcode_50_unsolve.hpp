/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_50
 * 时间: 7/10/19-4:34 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

//  Implement pow(x, n), which calculates x raised to the power n (xn).
//
//  Example 1:
//      Input: 2.00000, 10
//      Output: 1024.00000
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) {
            return 1;
        }else if(n == 1) {
            return x;
        }

        bool nagtive = (n > 0);
        n = abs(n);

        map<int, double> m;
        m[0] = 1;
        m[1] = x;
        m[2] = x * x;

        double ret = _pow(n, m);
        return nagtive ? ret : 1 / ret;
    }
    double _pow(int n, map<int, double> &m) {
        double ret, a = 0, b = 0;
        if(m.find(n) != m.end()) {
            return m[n];
        }else {
            if(n % 2) { // 奇数
                a = _pow((n - 1) / 2, m);
                m[(n - 1) / 2] = a;

                b = _pow(n / 2 + 1, m);
                m[n / 2 + 1] = b;

                ret = a * b;
            }else { // 偶数
                a = _pow(n / 2, m);
                m[n / 2] = a;

                ret = a * a;
            }
            return  ret;
        }
    }

    double myPow2(double x, int n) {
        if(n == 0)
            return 1;

        bool nagtive = (n > 0);
        double ret = x;
        n = abs(n);
        while(--n) {
            ret *= x;
        }
        return nagtive ? ret : 1 / ret;
    }
};

void test() {
    Solution s;
    // 8.95371
    // -1
    cout << s.myPow2(8.95371, 0) << endl;
}