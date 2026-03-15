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
        vector<int> nums{2, 7, 11, 15};
        int target = 9;
        vector<int> expected{0, 1};
        auto actual = s.twoSum(nums, target);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{3, 2, 4};
        int target = 6;
        vector<int> expected{1, 2};
        auto actual = s.twoSum(nums, target);
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> nums{3, 3};
        int target = 6;
        vector<int> expected{0, 1};
        auto actual = s.twoSum(nums, target);
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
