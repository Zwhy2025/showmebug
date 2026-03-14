#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 找到字符串中所有字母异位词
// https://leetcode.cn/problems/find-all-anagrams-in-a-string/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    string s = "";
    string p = "";
        vector<int> expected{/* TODO */};
        auto actual = s.findAnagrams(s, p);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
