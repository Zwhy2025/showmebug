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
        vector<int> nums{2,0,2,1,1,0};
        vector<int> expected{0,0,1,1,2,2};
        s.sortColors(nums);
        checkEqual("sample-1", nums, expected);
    }

    {
        vector<int> nums{2,0,1};
        vector<int> expected{0,1,2};
        s.sortColors(nums);
        checkEqual("sample-2", nums, expected);
    }

    return 0;
}
