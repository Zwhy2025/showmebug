#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 搜索二维矩阵 II
// https://leetcode.cn/problems/search-a-2d-matrix-ii/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<vector<int>> matrix{/* TODO */};
    int target = 0;
        bool expected = false;
        auto actual = s.searchMatrix(matrix, target);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
