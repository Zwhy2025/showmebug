#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}

int main() {
    Solution s;

    checkEqual("sample-1", s.longestCommonSubsequence("abcde", "ace"), 3);
    checkEqual("sample-2", s.longestCommonSubsequence("abc", "abc"), 3);
    checkEqual("sample-3", s.longestCommonSubsequence("abc", "def"), 0);

    return 0;
}
