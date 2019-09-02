/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice.hpp
 * 时间: 2019/8/31-17:49
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;


int test() {
    long long n, maxN;
    vector<long long> v;
    scanf("%lld", &n);

    for (int k = 0; k < n;  ++k) {
        scanf("%lld", &maxN);
        v.push_back(maxN);
    }
    maxN = v[0];
    long long preMin = 0;
    // [i, i + j]
    for (int i = 0; i < n; ++i) {
        for (int j = n - i - 1; j > i; --j) {
            long long sum = 0;
            long long minN = v[i];
            if(*min(v.begin() + i, v.begin() + i + j + 1) < preMin) {
                continue;
            }
            for (auto it = v.begin() + i; it != v.begin() + i + j + 1; ++it) {
                sum += *it;
                minN = minN > *it ? *it : minN;
            }
            preMin = minN;
            maxN = (maxN > (sum * minN) ? maxN : (sum * minN));
        }
    }
    printf("%lld", maxN);
    return 0;
}