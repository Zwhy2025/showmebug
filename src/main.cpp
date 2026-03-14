#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 编辑距离
// https://leetcode.cn/problems/edit-distance/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    string word1 = "";
    string word2 = "";
        int expected = 0;
        auto actual = s.minDistance(word1, word2);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
