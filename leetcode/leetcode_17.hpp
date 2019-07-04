//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

/*
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * */

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;

        if (digits.empty()) {
            return ret;
        } else if (digits.length() == 1) {
            for (char i : this->getStr(digits[0])) {
                string tmp;
                tmp += i;
                ret.push_back(move(tmp));
            }
            return ret;
        }

        list <string> str;
        for (char n : digits) {
            str.push_back(this->getStr(n));
        }

        func(ret, "", str);
        return ret;
    }

    string getStr(char n) {
        string ret;
        switch (n) {
            case '2':
                ret = "abc";
                break;
            case '3':
                ret = "def";
                break;
            case '4':
                ret = "ghi";
                break;
            case '5':
                ret = "jkl";
                break;
            case '6':
                ret = "mno";
                break;
            case '7':
                ret = "pqrs";
                break;
            case '8':
                ret = "tuv";
                break;
            case '9':
                ret = "wxyz";
                break;
            default:
                ret = "";
        }
        assert(!ret.empty());
        return ret;
    }

    void func(vector<string> &ret, const string &str, list <string> l) {
        if (l.empty()) {
            ret.push_back(str);
        } else {
            string s = l.front();
            l.pop_front();
            for (auto it:s) {
                this->func(ret, str + it, l);
            }
        }


    }

};

void test() {
    Solution s;
    for (const auto &it:s.letterCombinations("2")) {
        cout << it << " ";
    }
}
// ["adg","adh","adi","aeg","aeh","aei","afg","afh","afi","bdg","bdh","bdi","beg","beh","bei","bfg","bfh","bfi","cdg","cdh","cdi","ceg","ceh","cei","cfg","cfh","cfi"]
// ["adg","adh","adi","aeg","aeh","aei","afg","afh","afi","bdg","bdh","bdi","beg","beh","bei","bfg","bfh","bfi","cdg","cdh","cdi","ceg","ceh","cei","cfg","cfh","cfi"]
// adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi