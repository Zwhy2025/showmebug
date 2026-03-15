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
        vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
        vector<vector<int>> expected{{1,0,1},{0,0,0},{1,0,1}};
        s.setZeroes(matrix);
        checkEqual("sample-1", matrix, expected);
    }

    {
        vector<vector<int>> matrix{{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        vector<vector<int>> expected{{0,0,0,0},{0,4,5,0},{0,3,1,0}};
        s.setZeroes(matrix);
        checkEqual("sample-2", matrix, expected);
    }

    return 0;
}
