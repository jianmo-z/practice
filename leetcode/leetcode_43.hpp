/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_43
 * 时间: 7/5/19-11:16 AM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // 一个参数为空
        if(num1.empty() || num2.empty()) {
            return num1.empty() ? num2 : num1;
        }

        vector<string> middle;
        int num = 0;


        for(auto it = num1.rbegin(); it != num1.rend(); ++it, ++num) {
            middle.push_back(this->multiply_one(num2, *it, num));
            if(middle.size() == 2) {
                this->add(middle[0], middle[1]);
                middle.pop_back();
            }
        }
        int i = 0;
        for (i = 0; i < middle[0].size() - 1; ++i) {
            if(middle[0][i] != '0') {
                break;
            }
        }
        middle[0].erase(middle[0].begin(), middle[0].begin() + i);
        return middle[0];
    }

    // 两个字符串之和
    void add(string &num1, string &num2) {
        if(num1.length() < num2.length()) {
            swap(num1, num2);
        }

        int carry = 0;
        int num = 0;
        int i = 0;
        for(i = 0; i < num2.length(); ++i) {
            num = num1[num1.length() - i - 1] - '0' +
                    num2[num2.length() - i - 1] - '0' +
                    carry;
            num1[num1.length() - i - 1] = num % 10 + '0';
            carry = num / 10;
        }


        if(carry){
            string prefix = num1.substr(0, num1.size() - num2.size());
            string suffix = num1.substr(num1.size() - num2.size(), num1.size());
            string one = "1";
            add(prefix, one);
            num1 = prefix + suffix;
        }


    }

    // 一个数加1


    // 一个数乘以一个多位数
    string multiply_one(string num1, char num2, int num) {
        int carry = 0;
        string ret = num1;
        string app(num, '0');

        for (auto it = ret.rbegin(); it != ret.rend(); ++it) {
            auto tmp = ((num2 - '0') * (*it - '0')) + carry;
            *it = tmp % 10 + '0';
            carry = tmp / 10;
        }


        ret.append(app);

        return carry ? ret.insert(ret.begin(), carry + '0'), ret: ret;
    }
};

void test() {
    Solution s;
    string num1 = "329";
    string num2 = "0";

    cout << s.multiply(num1, num2) << endl;
}