//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

void test_01() {
	double x, y;
	double ans = 0;
	long long sum = 0;

	cin >> x >> y;
	++x, ++y;
	if (y > x) {
		swap(x, y);
	}

	if (x == y) {
		sum = x;
	} else if (x == 0 || y == 0) {
		sum = 0;
	} else {
		// bool (*v)[int(y)] = new bool [int(x)][int(y)];
		bool ** v;
		v = new bool *[int(x)];
		for(int i = 0; i < x; ++i) {
			v[i] = new bool[int(y)];
		}

		for (long long i = 1; i <= x; ++i) {
			ans = y * i / x;
			if (ans != (long long) (ans)) {
				if (!v[i][(long long) (ans)]) {
					++sum;
					v[i][(long long) (ans)] = true;
				}
				if (!v[i - 1][(long long) (ans)]) {
					++sum;
					v[i - 1][(long long) (ans)] = true;
				}
			}
		}
		for(int i = 0; i < x; ++i) {
			delete [] v[i];
		}
		delete [] v;
	}

	cout << sum;

}

int test_03() {
	int sum = 0, num = 0;
	string str;
	multimap<int, int> m;
	scanf("%d", &sum);
	for (int i = 0; i < sum; ++i) {
		cin >> str;
		if (str.find("add") != -1) {
			cin >> num;
			m.insert(pair<int, int>(num, num));
		} else {
			int j = 0;
			for (auto it = m.begin(); j < m.size(); ++it, ++j) {
				if (j == m.size() / 2) {
					cout << it->second;
					if (i != sum - 1) {
						cout << endl;
					}
					m.erase(it);
					break;
				}
			}
		}
	}
	return 0;

}

int test_03_1() {
	int sum = 0, num = 0;
	string str;
	vector<int> m;
	scanf("%d", &sum);

	str.resize(16);

	for(int i = 0; i < sum; ++i) {
		// cin >> str;
		scanf("%s", str.c_str());
		if(str.find("add") != -1) {
			// cin >> num;
			scanf("%d", &num);
			m.push_back(num);
		} else if (str.find("print") != -1){
			sort(m.begin(), m.end());
			printf("%d", m[m.size() / 2]);
			//cout << m[m.size() / 2];
			if(i != sum - 1){
				printf("\n");
				// cout << endl;
			}
			m.erase(m.begin() + m.size() / 2);
		}
		str.clear();
		str.resize(16);
	}
	return 0;

}

int getsum(vector<int> &v) {
	int ret = 0;
	for (int i = v.size() - 1; i != 0; --i) {
		ret += abs(v[i] - v[i - 1]);
	}
	return ret;
}

void dp(int i, int j, deque<int> &dq, vector<int> &v, int &max) {

	vector<int> v1 = v;
	vector<int> v2 = v;

	if (i == j) { // 数据被拿完了
		v.push_back(dq[i]);
		int sum = getsum(v);
		max = sum > max ? sum : max;
		return;
	}

	// 取左边的数
	v1.push_back(dq[i]);
	dp(i + 1, j, dq, v1, max);
	// 取右边的数
	v2.push_back(dq[j]);
	dp(i, j - 1, dq, v2, max);
}

int test_04() {
	int num = 0, tmp = 0, max = 0;
	deque<int> dq;
	vector<int> v;


	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		dq.push_back(tmp);
	}

	dp(0, dq.size() - 1, dq, v, max);
	cout << max;
	return 0;
}


void test() {
	test_01();
//	test_03();
//	test_03_1();
//	test_04();
}