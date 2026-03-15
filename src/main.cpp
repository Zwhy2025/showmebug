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
        vector<int> nums{2,2,1};
        checkEqual("sample-1", s.singleNumber(nums), 1);
    }

    {
        vector<int> nums{4,1,2,1,2};
        checkEqual("sample-2", s.singleNumber(nums), 4);
    }

    {
        vector<int> nums{1};
        checkEqual("sample-3", s.singleNumber(nums), 1);
    }

    return 0;
}
