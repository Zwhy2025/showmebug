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
        vector<int> nums{3,2,3};
        checkEqual("sample-1", s.majorityElement(nums), 3);
    }

    {
        vector<int> nums{2,2,1,1,1,2,2};
        checkEqual("sample-2", s.majorityElement(nums), 2);
    }

    return 0;
}
