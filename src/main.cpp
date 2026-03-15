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
        vector<int> nums{5,7,7,8,8,10};
        vector<int> expected{3,4};
        auto actual = s.searchRange(nums, 8);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{5,7,7,8,8,10};
        vector<int> expected{-1,-1};
        auto actual = s.searchRange(nums, 6);
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> nums{};
        vector<int> expected{-1,-1};
        auto actual = s.searchRange(nums, 0);
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
