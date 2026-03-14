#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 电话号码的字母组合
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    string digits = "";
        vector<string> expected{/* TODO */};
        auto actual = s.letterCombinations(digits);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
