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
        vector<int> height{1,8,6,2,5,4,8,3,7};
        int expected = 49;
        auto actual = s.maxArea(height);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> height{1,1};
        int expected = 1;
        auto actual = s.maxArea(height);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
