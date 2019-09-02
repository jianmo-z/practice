/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice.hpp
 * 时间: 2019/8/31-17:49
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

struct costumer{
    costumer() {
        this->a = 0;
        this->b = 0;
    }
    long long a;
    long long b;
};

int test() {
    long long n;
    vector<costumer> people;
    people.push_back(costumer());
    scanf("%lld", &n);
    for (int i = 0; i < n; ++i) {
        costumer tmp;
        scanf("%lld%lld", &tmp.a, &tmp.b);
        people.push_back(tmp);
    }


    // j号位置，不满意度 = a_i * (j - 1) + b_i * (n - j);
    bool isSwap = true;
    for(int i = n + 1; i > 1; --i) {
        for(int j = 1; j < i - 1; ++j) {
            if (!isSwap) break;
            isSwap = false;
            // 交换：后移一位, 前移一位
            int u1 = people[j].a * (j + 1 - 1) + people[j].b * (n - j - 1);
            int u2 = people[j + 1].a * (j + 1 - 1 - 1) + people[j + 1].b * (n - (j + 1) - 1);

            // 位置不变
            int u3 = people[j].a * (j - 1) + people[j].b * (n - j);
            int u4 = people[j + 1].a * (j - 1) + people[j + 1].b * (n - j);
            if (u1 + u2 < u3 + u4) {
                swap(people[j], people[j + 1]);
                isSwap = true;
            }
        }
    }
    long long count = 0;
    for (int k = 1; k < people.size(); ++k) {
        count += people[k].a * (k - 1) + people[k].b * (n - k);
    }
    printf("%lld", count);
    return 0;
}