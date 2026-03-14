#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 岛屿数量
// https://leetcode.cn/problems/number-of-islands/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<vector<char>> grid{/* TODO */};
        int expected = 0;
        auto actual = s.numIslands(grid);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
