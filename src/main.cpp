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
        vector<int> nums{100, 4, 200, 1, 3, 2};
        int expected = 4;
        auto actual = s.longestConsecutive(nums);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
        int expected = 9;
        auto actual = s.longestConsecutive(nums);
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> nums{};
        int expected = 0;
        auto actual = s.longestConsecutive(nums);
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
