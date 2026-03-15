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
        vector<int> nums{1,2,3,1};
        checkEqual("sample-1", s.rob(nums), 4);
    }

    {
        vector<int> nums{2,7,9,3,1};
        checkEqual("sample-2", s.rob(nums), 12);
    }

    return 0;
}
