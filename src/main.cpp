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
        vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
        vector<int> expected{1,2,3,6,9,8,7,4,5};
        auto actual = s.spiralOrder(matrix);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
        vector<int> expected{1,2,3,4,8,12,11,10,9,5,6,7};
        auto actual = s.spiralOrder(matrix);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
