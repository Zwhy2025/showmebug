#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 最大子数组和
// https://leetcode.cn/problems/maximum-subarray/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int expected = 6;
        auto actual = s.maxSubArray(nums);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{1};
        int expected = 1;
        auto actual = s.maxSubArray(nums);
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> nums{5, 4, -1, 7, 8};
        int expected = 23;
        auto actual = s.maxSubArray(nums);
        checkEqual("sample-3", actual, expected);
    }

    {
        vector<int> nums{-1, -2, -3};
        int expected = -1;
        auto actual = s.maxSubArray(nums);
        checkEqual("sample-4", actual, expected);
    }

    return 0;
}
