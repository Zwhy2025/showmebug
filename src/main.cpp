#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 前 K 个高频元素
// https://leetcode.cn/problems/top-k-frequent-elements/

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
        vector<int> expected{/* TODO */};
        auto actual = s.topKFrequent(nums, k);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
