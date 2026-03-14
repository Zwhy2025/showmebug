#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 最长公共子序列
// https://leetcode.cn/problems/longest-common-subsequence/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    string text1 = "";
    string text2 = "";
        int expected = 0;
        auto actual = s.longestCommonSubsequence(text1, text2);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
