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
        vector<int> nums{1,5,11,5};
        checkEqual("sample-1", s.canPartition(nums), true);
    }

    {
        vector<int> nums{1,2,3,5};
        checkEqual("sample-2", s.canPartition(nums), false);
    }

    return 0;
}
