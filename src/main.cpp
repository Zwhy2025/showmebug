#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 括号生成
// https://leetcode.cn/problems/generate-parentheses/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    int n = 0;
        vector<string> expected{/* TODO */};
        auto actual = s.generateParenthesis(n);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
