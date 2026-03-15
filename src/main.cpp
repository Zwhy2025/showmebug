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
        vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
        int expected = 6;
        auto actual = s.trap(height);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> height{4,2,0,3,2,5};
        int expected = 9;
        auto actual = s.trap(height);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
