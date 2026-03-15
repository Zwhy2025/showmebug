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
        vector<int> nums{2,3,-2,4};
        checkEqual("sample-1", s.maxProduct(nums), 6);
    }

    {
        vector<int> nums{-2,0,-1};
        checkEqual("sample-2", s.maxProduct(nums), 0);
    }

    return 0;
}
