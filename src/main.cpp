#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 盛最多水的容器
// https://leetcode.cn/problems/container-with-most-water/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<int> height{/* TODO */};
        int expected = 0;
        auto actual = s.maxArea(height);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
