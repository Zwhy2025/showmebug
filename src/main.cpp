#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 零钱兑换
// https://leetcode.cn/problems/coin-change/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<int> coins{/* TODO */};
    int amount = 0;
        int expected = 0;
        auto actual = s.coinChange(coins, amount);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
