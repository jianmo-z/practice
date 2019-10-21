/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_02.hpp
 * 时间: 9/7/2019-6:50 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    int left;
    int right;

    node(int data, int left, int right) : data(data), left(left), right(right) {}

    node() : data(0), left(0), right(0) {}
};

int get_sum(vector<node> &arr, int index, vector<int> &sum) {
    if (index == -1) {
        return 0;
    } else if(arr[index].right == -1 && arr[index].right == -1) {
        return arr[index].data;
    }
    int ldata = get_sum(arr, arr[index].left, sum);
    int rdata = get_sum(arr, arr[index].right, sum);
    sum[index] = ldata + rdata;
}

string dp(vector<node> &arr) {
    vector<bool> sign(arr.size(), false);
    for (auto it: arr) {
        if (it.left != -1)
            sign[it.left] = true;
        if (it.right != -1)
            sign[it.right] = true;
    }
    int unused = 0;
    for (int i = 0; i < sign.size(); ++i) {
        if (sign[i] == false) {
            unused = i;
        }
    }
    vector<int> sum(arr.size(), 0);
    sum[unused] =  get_sum(arr, unused, sum);
    for (int j = 0; j < sum.size(); ++j) {
        if(sum[j] > sum[j + 1])
            return "NO";
    }
    return "YES";

}

int test() {
    int t = 0;
    int n = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<node> arr;
        node tmp;
        for (int j = 0; j < n; ++j) {
            cin >> tmp.data >> tmp.left >> tmp.right;
            arr.push_back(tmp);
        }
        if (i + 1 == t) {
            cout << dp(arr);
        } else {
            cout << dp(arr) << endl;
        }
        arr.resize(0);
    }
    return 0;
}
