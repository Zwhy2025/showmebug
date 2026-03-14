#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 每日温度
// https://leetcode.cn/problems/daily-temperatures/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<int> temperatures{/* TODO */};
        vector<int> expected{/* TODO */};
        auto actual = s.dailyTemperatures(temperatures);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
