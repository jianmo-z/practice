//
// Created by pip on 19-3-10.
// 参考链接：https://blog.csdn.net/Hilavergil/article/details/79851299
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // 递归方式 recursion
    vector<string> generateParenthesis(int n) {
        string container;
        vector<string> ret;
        recursion(n, n, container, ret);
//        recursion_2(n, n, container, ret);
        return ret;
    }

    // 递归方式实现,如果左括号个数小于等于右括号个数，则需选择左括号
    void recursion(int left, int right, string container, vector<string> &ret) {
        if(left == 0 && right == 0) {
            ret.push_back(container);
            return;
        }
        if(left > 0) { // 选还是不选，选需要什么条件
            recursion(left - 1, right, container + "(", ret);
        }
        if(left < right) { // 选还是不选，选需要什么条件
            recursion(left, right - 1, container + ")", ret);
        }
    }

    // 猜想二，去掉匹配的约束条件，打印出所有的可能结果，一共 C(2*n)n 个，排列组合,(2*n)! / n! / n!,需要去除对称情况出现
    void recursion_2(int left, int right, string container, vector<string> &ret) {
        if(left == 0 && right == 0) {
            ret.push_back(container);
            return;
        }
        // ret.push_back(container);
        if (left > 0)
            recursion_2(left - 1, right, container + "(", ret);
        if (right > 0)
            recursion_2(left, right - 1, container + ")", ret);
    }

    // 非递归实现
    void non_recursion() {
        int n = 4;
        for(int i = 0; i < n; i++) {

        }
    }
};

void test() {
    Solution s;
    auto ret = s.generateParenthesis(5);

    for (auto i = ret.begin(); i != ret.end(); i++) {
        cout << *i << endl;
    }
    cout << "一共有:" << ret.size() << endl;

}