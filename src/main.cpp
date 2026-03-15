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
        int n = 2;
        int expected = 2;
        auto actual = s.climbStairs(n);
        checkEqual("sample-1", actual, expected);
    }

    {
        int n = 3;
        int expected = 3;
        auto actual = s.climbStairs(n);
        checkEqual("sample-2", actual, expected);
    }

    {
        int n = 1;
        int expected = 1;
        auto actual = s.climbStairs(n);
        checkEqual("sample-3", actual, expected);
    }

    {
        int n = 5;
        int expected = 8;
        auto actual = s.climbStairs(n);
        checkEqual("sample-4", actual, expected);
    }

    return 0;
}
