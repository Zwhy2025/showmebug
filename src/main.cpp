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
        vector<int> nums{1,3,-1,-3,5,3,6,7};
        int k = 3;
        vector<int> expected{3,3,5,5,6,7};
        auto actual = s.maxSlidingWindow(nums, k);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{1};
        int k = 1;
        vector<int> expected{1};
        auto actual = s.maxSlidingWindow(nums, k);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
