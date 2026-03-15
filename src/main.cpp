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
        vector<int> nums{-1,0,1,2,-1,-4};
        auto actual = s.threeSum(nums);
        for (auto &v : actual) sort(v.begin(), v.end());
        sort(actual.begin(), actual.end());
        vector<vector<int>> expected{{-1,-1,2},{-1,0,1}};
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{0,1,1};
        auto actual = s.threeSum(nums);
        vector<vector<int>> expected{};
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> nums{0,0,0};
        auto actual = s.threeSum(nums);
        vector<vector<int>> expected{{0,0,0}};
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
