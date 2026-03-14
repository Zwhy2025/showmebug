#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 轮转数组
// https://leetcode.cn/problems/rotate-array/

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
        s.rotate(nums, k);
        cout << "sample-1: executed (add expected checks if needed)" << '\n';
    }

    return 0;
}
