#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 和为 K 的子数组
// https://leetcode.cn/problems/subarray-sum-equals-k/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<int> nums{/* TODO */};
    int k = 0;
        int expected = 0;
        auto actual = s.subarraySum(nums, k);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
