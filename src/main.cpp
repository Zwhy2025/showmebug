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
        vector<vector<int>> grid{{2,1,1},{1,1,0},{0,1,1}};
        checkEqual("sample-1", s.orangesRotting(grid), 4);
    }

    {
        vector<vector<int>> grid{{2,1,1},{0,1,1},{1,0,1}};
        checkEqual("sample-2", s.orangesRotting(grid), -1);
    }

    {
        vector<vector<int>> grid{{0,2}};
        checkEqual("sample-3", s.orangesRotting(grid), 0);
    }

    return 0;
}
