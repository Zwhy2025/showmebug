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
        vector<int> coins{1,2,5};
        checkEqual("sample-1", s.coinChange(coins, 11), 3);
    }

    {
        vector<int> coins{2};
        checkEqual("sample-2", s.coinChange(coins, 3), -1);
    }

    {
        vector<int> coins{1};
        checkEqual("sample-3", s.coinChange(coins, 0), 0);
    }

    return 0;
}
