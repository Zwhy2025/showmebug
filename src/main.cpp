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
        vector<int> nums{1,2,0};
        int expected = 3;
        auto actual = s.firstMissingPositive(nums);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{3,4,-1,1};
        int expected = 2;
        auto actual = s.firstMissingPositive(nums);
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> nums{7,8,9,11,12};
        int expected = 1;
        auto actual = s.firstMissingPositive(nums);
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
