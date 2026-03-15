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
        vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
        checkEqual("sample-1", s.minPathSum(grid), 7);
    }

    {
        vector<vector<int>> grid{{1,2,3},{4,5,6}};
        checkEqual("sample-2", s.minPathSum(grid), 12);
    }

    return 0;
}
