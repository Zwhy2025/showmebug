#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 合并区间
// https://leetcode.cn/problems/merge-intervals/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<vector<int>> intervals{/* TODO */};
        vector<vector<int>> expected{/* TODO */};
        auto actual = s.merge(intervals);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
