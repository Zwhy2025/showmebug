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

#include <algorithm>

int main() {
    Solution s;

    {
        auto actual = s.solveNQueens(4);
        sort(actual.begin(), actual.end());
        vector<vector<string>> expected{{".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."}};
        sort(expected.begin(), expected.end());
        checkEqual("sample-1", actual, expected);
    }

    {
        auto actual = s.solveNQueens(1);
        vector<vector<string>> expected{{"Q"}};
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
