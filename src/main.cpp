#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 最长回文子串
// https://leetcode.cn/problems/longest-palindromic-substring/

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
        string expected = "";
        auto actual = s.longestPalindrome(s);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
