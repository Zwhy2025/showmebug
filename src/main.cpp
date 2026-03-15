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
        vector<int> nums{1,2,3};
        vector<int> expected{1,3,2};
        s.nextPermutation(nums);
        checkEqual("sample-1", nums, expected);
    }

    {
        vector<int> nums{3,2,1};
        vector<int> expected{1,2,3};
        s.nextPermutation(nums);
        checkEqual("sample-2", nums, expected);
    }

    {
        vector<int> nums{1,1,5};
        vector<int> expected{1,5,1};
        s.nextPermutation(nums);
        checkEqual("sample-3", nums, expected);
    }

    return 0;
}
