/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_5.hpp
 * 时间: 2/13/2020-1:07 PM
 * 作者: Pip
 */


/*
6
C2
D3
S4
C5
C6
C4


J1
J2
 * */

#include <bits/stdc++.h>

using namespace std;

struct card {
    card() {
        c[0] = 0;
        c[1] = 0;
        num = 0;
        isUsed = false;
    }

    char c[2];
    int num;
    bool isUsed;

    bool operator==(card &c) {
        return this->num == c.num;
    }
};

void sort_by_num(vector<card> &data) {
    sort(data.begin(), data.end(), [](card &c1, card &c2) -> bool { return c1.num < c2.num; });
}

int nextCard(vector<card> &data, int i) {
    for (; i < data.max_size(); ++i) {
        if (!data[i].isUsed)
            return i;
    }
    return -1;
}

int getNSamecard(vector<card> &data, int n, bool Use = true) {
    int score[6] = {0, 0, 2, 4, 5, 0};
    bool isSame = true;
    vector<int> cards(n);

    for (int i = 0; i < data.size(); ++i) {
        int index = i;
        for (int j = 0; j < n; ++j) {
            cards[j] = nextCard(data, index++);
            if(cards[j] == -1)
                return 0;
            else if(j > 0) {
                if (cards[j] == cards[j - 1])
                    return 0;
            }
        }
        isSame = true;
        for (int j = 0; j < n - 1; ++j) {
            if (data[cards[j]].num != data[cards[j + 1]].num) {
                isSame = false;
                break;
            }
        }
        if (isSame) {
            for (int j = 0; j < n; ++j) {
                data[cards[j]].isUsed = Use;
            }
            break;
        }
    }

    return score[n];
}

int get5card(vector<card> &data, bool Use = true) {
    bool isOrder = true;
    int cards[5];

    for (int i = 0; i < data.size() - 5; ++i) {
        isOrder = true;
        cards[0] = nextCard(data, i);
        for (int j = 1; j < 5; ++j) {
            cards[j] = nextCard(data, i);
            if (data[cards[j]].num - data[cards[j - 1]].num != 1) {
                isOrder = false;
                break;
            }
        }
        if (isOrder) {
            for (int j = 0; j < 5; ++j) {
                data[cards[j]].isUsed = Use;
            }
            return 5;
        }
    }
    return 0;
}

void dp(vector<card> &data, int &score) {
    if (getNSamecard(data, 2, false) == 0 &&
        getNSamecard(data, 3, false) == 0 &&
        getNSamecard(data, 4, false) == 0 &&
        get5card(data, false) == 0) {
        return;
    }
    // 动态方程: score = max(2张牌 + left, 3张牌 + left, 4张牌 + left, 5张牌 + left)
    vector<card> backup = data;
    int score2 = score + getNSamecard(data, 2);
    dp(data, score2);

    data = backup;
    int score3 = score + getNSamecard(data, 3);
    dp(data, score3);

    data = backup;
    int score4 = score + getNSamecard(data, 4);
    dp(data, score4);

    data = backup;
    int score5 = score + get5card(data);
    dp(data, score5);

    score = max({score2, score3, score4, score5});

}

int main() {
    int n = 0;
    bool j[2] = {false, false};
    string s;
    cin >> n;
    vector<card> data;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (s.c_str()[0] == 'J') {  // 处理大小王
            s.c_str()[1] == '1' ? j[0] = true : j[1] = true;
            continue;
        }
        card tmp;
        tmp.c[0] = s[0];
        tmp.num = atoi(s.c_str() + 1);
        data.push_back(tmp);
    }
    // S黑桃， H红桃，C梅花，D方块
    // J1大王，J2小王

    sort_by_num(data);
    int score = 0;
    dp(data, score);
    cout << score;

    return 0;
}