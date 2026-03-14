#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 买卖股票的最佳时机
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<int> prices{/* TODO */};
        int expected = 0;
        auto actual = s.maxProfit(prices);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
