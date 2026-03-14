#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 寻找两个正序数组的中位数
// https://leetcode.cn/problems/median-of-two-sorted-arrays/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<int> nums1{/* TODO */};
    vector<int> nums2{/* TODO */};
        double expected = 0;
        auto actual = s.findMedianSortedArrays(nums1, nums2);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
