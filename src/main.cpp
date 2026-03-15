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
        vector<int> nums{3,4,5,1,2};
        checkEqual("sample-1", s.findMin(nums), 1);
    }

    {
        vector<int> nums{4,5,6,7,0,1,2};
        checkEqual("sample-2", s.findMin(nums), 0);
    }

    {
        vector<int> nums{11,13,15,17};
        checkEqual("sample-3", s.findMin(nums), 11);
    }

    return 0;
}
