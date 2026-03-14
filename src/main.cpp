#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 搜索旋转排序数组
// https://leetcode.cn/problems/search-in-rotated-sorted-array/

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
    int target = 0;
        int expected = 0;
        auto actual = s.search(nums, target);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
