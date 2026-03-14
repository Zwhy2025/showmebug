#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 最小路径和
// https://leetcode.cn/problems/minimum-path-sum/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<vector<int>> grid{/* TODO */};
        int expected = 0;
        auto actual = s.minPathSum(grid);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
