#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 只出现一次的数字
// https://leetcode.cn/problems/single-number/

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
        auto actual = s.singleNumber(nums);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
