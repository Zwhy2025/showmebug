#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        vector<int> prices{7, 1, 5, 3, 6, 4};
        int expected = 5;
        auto actual = s.maxProfit(prices);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> prices{7, 6, 4, 3, 1};
        int expected = 0;
        auto actual = s.maxProfit(prices);
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> prices{2, 4, 1};
        int expected = 2;
        auto actual = s.maxProfit(prices);
        checkEqual("sample-3", actual, expected);
    }

    {
        vector<int> prices{1};
        int expected = 0;
        auto actual = s.maxProfit(prices);
        checkEqual("sample-4", actual, expected);
    }

    return 0;
}
