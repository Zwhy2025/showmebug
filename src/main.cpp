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
        vector<int> nums{1,3,4,2,2};
        checkEqual("sample-1", s.findDuplicate(nums), 2);
    }

    {
        vector<int> nums{3,1,3,4,2};
        checkEqual("sample-2", s.findDuplicate(nums), 3);
    }

    {
        vector<int> nums{3,3,3,3,3};
        checkEqual("sample-3", s.findDuplicate(nums), 3);
    }

    return 0;
}
