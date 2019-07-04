//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int i = 0, j = 0;
		if(needle.size() == 0)
			return 0;
		for(i = 0; i < haystack.size(); ++i) {
			for(j = 0; j < needle.size(); ++j) {
				if(haystack[i + j ] != needle[j])
					break;
			}
			if(j == needle.size())
				break;
		}
		return i == haystack.size() ? -1 : i;
	}
private:
};

void test() {
	Solution s;
	cout << s.strStr("", "") << endl;
}