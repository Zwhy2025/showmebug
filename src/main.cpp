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
        vector<int> nums{1,2,3};
        auto actual = s.subsets(nums);
        for (auto &v : actual) sort(v.begin(), v.end());
        sort(actual.begin(), actual.end());
        vector<vector<int>> expected{{},{1},{1,2},{1,2,3},{1,3},{2},{2,3},{3}};
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{0};
        auto actual = s.subsets(nums);
        sort(actual.begin(), actual.end());
        vector<vector<int>> expected{{},{0}};
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
