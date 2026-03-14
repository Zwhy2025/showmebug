#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 矩阵置零
// https://leetcode.cn/problems/set-matrix-zeroes/

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
        s.setZeroes(matrix);
        cout << "sample-1: executed (add expected checks if needed)" << '\n';
    }

    return 0;
}
