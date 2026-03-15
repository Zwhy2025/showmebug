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
        vector<int> nums{1,3,5,6};
        checkEqual("sample-1", s.searchInsert(nums, 5), 2);
    }

    {
        vector<int> nums{1,3,5,6};
        checkEqual("sample-2", s.searchInsert(nums, 2), 1);
    }

    {
        vector<int> nums{1,3,5,6};
        checkEqual("sample-3", s.searchInsert(nums, 7), 4);
    }

    return 0;
}
