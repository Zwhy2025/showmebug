#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 无重复字符的最长子串
// https://leetcode.cn/problems/longest-substring-without-repeating-characters/

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
        int expected = 0;
        auto actual = s.lengthOfLongestSubstring(s);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
