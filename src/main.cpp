#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 搜索插入位置
// https://leetcode.cn/problems/search-insert-position/

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
        auto actual = s.searchInsert(nums, target);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
