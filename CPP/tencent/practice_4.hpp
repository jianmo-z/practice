/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice.hpp
 * 时间: 2019/8/31-17:49
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

struct column{
    int a;
    int b;
};

int test() {
    int t, k, a, b;
    vector<column> v;

    cin >> t >> k;
    for (int i = 0; i < t; ++i) {
        column tmp;
        scanf("%d%d", &tmp.a, &tmp.b);
        v.push_back(tmp);
    }

    int size = 0;
    for (auto i: v) {
        // 只有红花
        long long  sum = 0;
        for (int j = i.a; j < i.b + 1; ++j) {
            sum += i.b - i.a + 1;
            for (int l = 1; l < j; ++l) {
                if (k * l > i.b + 1)
                    break;
                sum += l - k * l + 1;
                if (sum > 1e9+7) {
                    sum = sum % (long long)(1e9+7);
                }
            }
        }
        ++size;
        if(size == v.size()){
            printf("%d", sum);
        } else {
            printf("%d\n", sum);
        }
    }

    return 0;
}