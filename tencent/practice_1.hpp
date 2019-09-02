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
    long long times = 0;
    long long a, b, m, n;
    vector<long long> b1;
    vector<long long> b2;
    vector<long long> k1;
    vector<long long> k2;
    scanf("%lld%lld", &m, &n);

    for(int i = 0; i < m; ++i) {
            (a & 1) ? b1.push_back(a) : b2.push_back(a);
    }
    for(int i = 0; i < n; ++i) {
            (b & 1) ? k1.push_back(b) : k2.push_back(b);
    }


    times = min(b1.size(), k2.size()) + min(b2.size(), k1.size());
    printf("%lld", times);

    return 0;
}