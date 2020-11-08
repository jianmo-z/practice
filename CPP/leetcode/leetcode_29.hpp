//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

// assume that your function returns 2^31 − 1 when the division result overflows.
class Solution {
public:

	// 自己代码，没测试出来
	int divide1(int dividend, int divisor) {
		bool tag = false;
		if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
			tag = true;
		long ret = 0;


		long _dividend = labs(dividend);
		long _divisor = labs(divisor);

		if (1 == _divisor) { // 优化
			ret = tag ? -_dividend : _dividend;
		} else {
			for (;;) {
				if (_dividend >= _divisor) {
					++ret;
				} else {
					break;
				}
				_dividend = _dividend - _divisor;
			}
			ret = tag ? -ret : ret;
		}

		if (ret > 2147483647 || ret < -2147483648) // 处理溢出
			ret = tag ? -2147483647 : 2147483647;
		return ret;
	}

	// 别人的代码。。。。。。
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1) return INT_MAX;
		if (dividend != INT_MIN && divisor != INT_MIN && abs(dividend) < abs(divisor)) return 0;
		bool negative = (dividend > 0) ^ (divisor > 0);
		int a = dividend, b = divisor;
		if (a > 0) a = -a;
		if (b > 0) b = -b;

		//a<0 b<0
		int ans = 0;
		while (a <= b) {
			int s = -1; // 处理溢出
			int m = b;
			while (a - m <= m) {
				s = s + s;
				m = m + m;
			}
			ans += s;
			a -= m;
		}
		return negative ? ans : -ans;
	}
};

void test() {
	Solution s;
	// 949909485
	// 1593896380
	// -999511578
	//-2147483648
	cout << s.divide(-999511578, -2147483648) << endl;
}