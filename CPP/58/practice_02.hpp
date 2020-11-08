/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_02.hpp
 * 时间: 9/12/2019-8:40 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/*
1
2

///////
6
7
6
3
5
6
2
 *
 * */
int test() {
    multimap
    int n = 0;
    int sum = 0;
    cin >> n;
    if(n == 1) {
        cout << 1;
        return 0;
    } else if(n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> student(n, 0);
    vector<int> cookie(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> sum;
        student[i] = sum;
    }
    // 3 1 2 3
    for (int j = 0; j < n; ++j) {
        if (j >= 1 && student[j] > student[j - 1]) {
            cookie[j] = cookie[j - 1] + 1;
        } else if ((j + 1) < n && student[j] > student[j + 1]) {
            cookie[j] = cookie[j + 1] + 1;
        }

    }

    sum = 0;
    for (int i = 0; i < cookie.size(); ++i) {
        sum += cookie[i];
    }
    cout << sum;
    return 0;
}