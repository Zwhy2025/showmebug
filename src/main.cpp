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
        vector<int> nums{1,2,3,4,5,6,7};
        int k = 3;
        vector<int> expected{5,6,7,1,2,3,4};
        s.rotate(nums, k);
        checkEqual("sample-1", nums, expected);
    }

    {
        vector<int> nums{-1,-100,3,99};
        int k = 2;
        vector<int> expected{3,99,-1,-100};
        s.rotate(nums, k);
        checkEqual("sample-2", nums, expected);
    }

    return 0;
}
