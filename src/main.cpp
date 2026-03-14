#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 爬楼梯
// https://leetcode.cn/problems/climbing-stairs/

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
        int expected = 0;
        auto actual = s.climbStairs(n);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
