#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 柱状图中最大的矩形
// https://leetcode.cn/problems/largest-rectangle-in-histogram/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<int> heights{/* TODO */};
        int expected = 0;
        auto actual = s.largestRectangleArea(heights);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
