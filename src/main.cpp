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
        vector<int> heights{2,1,5,6,2,3};
        checkEqual("sample-1", s.largestRectangleArea(heights), 10);
    }

    {
        vector<int> heights{2,4};
        checkEqual("sample-2", s.largestRectangleArea(heights), 4);
    }

    return 0;
}
