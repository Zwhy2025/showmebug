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
        vector<int> nums{0, 1, 0, 3, 12};
        vector<int> expected{1, 3, 12, 0, 0};
        s.moveZeroes(nums);
        checkEqual("sample-1", nums, expected);
    }

    {
        vector<int> nums{0};
        vector<int> expected{0};
        s.moveZeroes(nums);
        checkEqual("sample-2", nums, expected);
    }

    {
        vector<int> nums{1, 2, 3};
        vector<int> expected{1, 2, 3};
        s.moveZeroes(nums);
        checkEqual("sample-3", nums, expected);
    }

    {
        vector<int> nums{0, 0, 1};
        vector<int> expected{1, 0, 0};
        s.moveZeroes(nums);
        checkEqual("sample-4", nums, expected);
    }

    {
        vector<int> nums{1, 0, 1};
        vector<int> expected{1, 1, 0};
        s.moveZeroes(nums);
        checkEqual("sample-5", nums, expected);
    }

    return 0;
}
