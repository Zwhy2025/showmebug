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
        vector<int> nums{10,9,2,5,3,7,101,18};
        checkEqual("sample-1", s.lengthOfLIS(nums), 4);
    }

    {
        vector<int> nums{0,1,0,3,2,3};
        checkEqual("sample-2", s.lengthOfLIS(nums), 4);
    }

    {
        vector<int> nums{7,7,7,7,7,7,7};
        checkEqual("sample-3", s.lengthOfLIS(nums), 1);
    }

    return 0;
}
