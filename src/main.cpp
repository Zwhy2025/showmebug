#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 数组中的第K个最大元素
// https://leetcode.cn/problems/kth-largest-element-in-an-array/

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
        auto actual = s.findKthLargest(nums, k);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
