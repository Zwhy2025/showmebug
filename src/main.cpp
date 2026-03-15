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
        vector<int> nums{1,1,1};
        int k = 2;
        int expected = 2;
        auto actual = s.subarraySum(nums, k);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{1,2,3};
        int k = 3;
        int expected = 2;
        auto actual = s.subarraySum(nums, k);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
