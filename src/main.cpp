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
        vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        checkEqual("sample-1", s.searchMatrix(matrix, 3), true);
    }

    {
        vector<vector<int>> matrix{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        checkEqual("sample-2", s.searchMatrix(matrix, 13), false);
    }

    return 0;
}
