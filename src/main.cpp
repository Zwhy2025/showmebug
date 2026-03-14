#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 寻找旋转排序数组中的最小值
// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/

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
        int expected = 0;
        auto actual = s.findMin(nums);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
