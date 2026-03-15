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
        auto actual = s.permute(nums);
        sort(actual.begin(), actual.end());
        vector<vector<int>> expected{{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{0,1};
        auto actual = s.permute(nums);
        sort(actual.begin(), actual.end());
        vector<vector<int>> expected{{0,1},{1,0}};
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> nums{1};
        auto actual = s.permute(nums);
        vector<vector<int>> expected{{1}};
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
