//
// Created by pip on 19-4-5.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// 使用dp求解
	// 8 ms	9.6 MB
	int longestValidParentheses(string s) {
		int ret = 0;
		int left_parenthesis = 0;
		if (!s.size()) { // 空串返回
			return ret;
		}
		vector<int> dp(s.size(), 0);

		// ()
		// 看当前括号的前一个括号的匹配情况
		// ()()
		/* 情况一：
		 * ( ) ( ( ) )
		 * 0 1 2 3 4 5
		 * 当 i = 5 时需要加上 i = 1 的dp[i]
		 *
		 * 情况二：
		 * ( ) ) ( )
		 * 0 1 2 3 4
		 *    当 i = 2 时，dp[i] = (s[j] == '(') ? dp[i - 1] + 2 : 0,
		 * 则dp[i] = 0。
		 *
		 * */

		int j = 0;
		for (int i = 1; i < s.size(); ++i) {
			if(s[i] == ')') {
				j = (i - 1) - dp[i - 1];
				if (j >= 0) {
					dp[i] = (s[j] == '(') ? dp[i - 1] + 2 : 0;

					dp[i] = ( (j - 1 > 0) && s[j - 1] == ')' )
							? dp[i] + dp[j - 1]
							: dp [i];

				}
			}
		}

		ret = *max_element(dp.begin(), dp.end());
		return ret;
	}

};

void test() {
	Solution s;
	cout << "max:" << s.longestValidParentheses(string(")()())()()(")) << endl; // 4
	// cout << "max:" << s.longestValidParentheses(string("())(())(()(((((())()())()())()((()(((()()))())(((()()(((())())))()()))))(()))))))(((((((())))(())(())(()()((()))))))()((())))))(())))))(")) << endl; // 2
	cout << "max:" << s.longestValidParentheses(string("(()))())(")) << endl; // 4
	cout << "max:" << s.longestValidParentheses(string("(()")) << endl; // 2
	cout << "max:" << s.longestValidParentheses(string(")()())")) << endl; // 4
}