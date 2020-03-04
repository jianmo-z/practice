/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice.hpp
 * 时间: 2019/8/31-17:49
 * 作者: Pip
 */

/*
2
4 1 1 1 1 1 1 1 1 1
1 1 1 1 1 4 0 1 1 1
 * */


#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &array, int &times, int index) {
    if (array[9] == 2)
        return;

    // 从大向小合并
    if (array[index] > 1) {
        times += 1;
        array[index] -= 2;
        array[index + 1] += 1;
        merge(array, times, index + 1);
        return;
    }

    if (index > 0)
        merge(array, times, index - 1);
}

int test() {
    int n = 0;

    vector<int> array(10);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        // 接收数据
        for (int j = 0; j < 10; ++j) {
            cin >> array[j];
        }
        int times = 1;

        merge(array, times, 8);

        cout << times;
        if (i + 1 != n)
            cout << endl;
    }

    return 0;
}