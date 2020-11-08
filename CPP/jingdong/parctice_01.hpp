//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

/*
#include <bits/stdc++.h>

using namespace std;

int main() {

}
*/

int test_01() {
    int n, x, y;
    vector<pair<int, int>> v;
    vector<queue<int>> vq;
    map<int, int> m;
    int len = 0, max_size = 0;

    cin >> n; // 接收数据n
    v.resize(pow(2, n + 1));

    // 接收节点信息
    for (int i = 0; i < n - 1; ++i) {
        // 当前---前一个
        cin >> x >> y;
        if (y == 1) {
            m[x] = 1;
            ++len;
        } else {
            m[x] = m[y] + 1;
            if(x - y == 1 && x == max_size) {
                ;
            } else {
                ++len;
            }
        }
    }


    int max = m.begin()->second;
    for (auto it : m) {
        if (it.second + 1 > max) {
            max = it.second + 1;
        }
    }
    cout << len;
    return 0;
}

int dp(string t, vector<string> &v, int max) {
    int min_index = -1, len;
    int tmp_index;
    bool isfind = false;

    // 退出条件
    if (t.size() == 0) {
        return max;
    }

    for (string &it:v) {
        tmp_index = t.find(it);
        if (tmp_index == -1) {
            continue;
        }

        // 找到最前面的一个那个
        if (min_index == -1) {
            min_index = tmp_index;
            len = it.size();
            isfind = true;
        } else if (min_index > tmp_index) {
            min_index = tmp_index;
            len = it.size();
            isfind = true;
        }
    }

    if (isfind) {
        ++max;
    }

    // 不删
    // int ret1 = dp(t, v, max);
    // 删
    t.erase(0, min_index + len);
    int ret2 = dp(t, v, max);
    return max > ret2 ? max : ret2;
}

/*
3
aa
b
ac
bbaac
 */
int test_02() {
    int m, max = 0;
    string t;
    vector<string> v;

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        v.push_back(t);
    }
    cin >> t;

    cout << dp(t, v, max) << endl;

    return 0;
}

void test() {
    test_01();
//    test_02();
}