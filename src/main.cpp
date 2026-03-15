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
        vector<int> candidates{2,3,6,7};
        auto actual = s.combinationSum(candidates, 7);
        for (auto &v : actual) sort(v.begin(), v.end());
        sort(actual.begin(), actual.end());
        vector<vector<int>> expected{{2,2,3},{7}};
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> candidates{2,3,5};
        auto actual = s.combinationSum(candidates, 8);
        for (auto &v : actual) sort(v.begin(), v.end());
        sort(actual.begin(), actual.end());
        vector<vector<int>> expected{{2,2,2,2},{2,3,3},{3,5}};
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> candidates{2};
        auto actual = s.combinationSum(candidates, 1);
        vector<vector<int>> expected{};
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
