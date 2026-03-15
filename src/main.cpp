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
        vector<int> nums{1,2,3,4};
        vector<int> expected{24,12,8,6};
        auto actual = s.productExceptSelf(nums);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{-1,1,0,-3,3};
        vector<int> expected{0,0,9,0,0};
        auto actual = s.productExceptSelf(nums);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
