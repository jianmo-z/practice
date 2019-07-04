//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

// 20 4 1 2 5 10
// 5
bool make_i(map<unsigned long, unsigned long> mkey2, unsigned long i) {
	for (auto it = mkey2.rbegin(); it != mkey2.rend(); ++it) {
		while ((*it).second) {
			if ((*it).first <= i) {
				i -= (*it).first;
				mkey2[(*it).first] = --(*it).second;
			} else {
				break;
			}
		}
	}
	return i == 0;
}

void test_01() {
	unsigned long ret = 0;
	unsigned long m, n, tmp;
	vector<unsigned long> v;
	vector<unsigned long> v1;
	map<unsigned long, unsigned long> mkey1;
	map<unsigned long, unsigned long> mkey2;

	cin >> m >> n;
	for (unsigned long i = 0; i < n; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 1; i <= m; ++i) {
		// 判断mkey2是否能组成i值
		if (make_i(mkey2, i)) {
			continue;
		}

		tmp = i;
		for (auto it = v.rbegin(); it != v.rend() && tmp;) {
			if (tmp >= *it) {
				if (mkey1.find(*it) != mkey1.end()) {
					mkey1[*it] = mkey1[*it] + 1;
				} else {
					mkey1.insert(pair<unsigned long, unsigned long>(*it, 1));
				}
				tmp -= *it;
			} else {
				++it;
			}
		}


		for (auto it : mkey1) {
			if (mkey2.find(it.first) == mkey2.end()) {
				mkey2.insert(pair<unsigned long, unsigned long>(it.first, it.second));
			} else {
				mkey2[it.first] = (mkey1[it.first] > mkey2[it.first]) ? mkey1[it.first] : mkey2[it.first];
			}
		}
//		cout << "mkey1 => ";
//		for(auto it : mkey1) {
//			cout << "[" << it.first << "]" << it.second << " " ;
//		}
//		cout << endl;
//		cout << "mkey2 => ";
//		for(auto it : mkey2) {
//			cout << "[" << it.first << "]" << it.second << " " ;
//		}
//		cout << endl << "========================================="<< endl;
		mkey1.clear();
	}
	for (auto it : mkey2) {
		ret += it.second;
	}
	cout << ret;
}

void test_02() {
	stack<char> s;
	string str;
	int n = 0;
	cin >> n >> str;
//	cout << n << endl;
//	cout << str << endl;
	for (char it: str) {
		if (s.empty()) {
			s.push(it);
		} else {
			switch (it) {
				case '0': {
					if (s.top() == '1') {
						s.pop();
					} else {
						s.push(it);
					}
				}
					break;
				case '1': {
					if (s.top() == '0') {
						s.pop();
					} else {
						s.push(it);
					}
				}
					break;
			}
		}
	}

	cout << s.size();
}

void dp_03(unsigned long n, vector<unsigned long> &d, vector<unsigned long> &p, unsigned long money, long &min,
           unsigned long cur) {

	if (0 == n) {
		if (cur < d[0]) {
			money += p[0];
		}
		if (min == -1) { // 第一次时候
			min = money;
		} else {
			min = (money < min) ? money : min;
		}
		return;
	}

	if (cur < d[n]) {// 贿赂, cur < d[n],必须要贿赂
		dp_03(n - 1, d, p, money + p[n], min, d[n] + cur);
	} else {// 不贿赂
		dp_03(n - 1, d, p, money, min, cur);
	}
}

// 3 8 5 10 1 1 2
// 4 1 2 4 8 1 2 1 2

/*
 *  4
 *  1 4 2 8
 *  1 2 1 2
 *  1 2 2
 * */
void test_03() {
	unsigned long n = 0, tmp;
	long min = -1;
	vector<unsigned long> d;
	vector<unsigned long> p;
	cin >> n;
	for (unsigned long i = 0; i < n; i++) {
		cin >> tmp;
		d.insert(d.begin(), tmp);
	}
	for (unsigned long i = 0; i < n; i++) {
		cin >> tmp;
		p.insert(p.begin(), tmp);
	}
	if (n > 0) {
		dp_03(n - 1, d, p, 0, min, 0);
	}
	cout << min;
}


void test() {
	test_01();
	// test_02();
	//	test_03();
}