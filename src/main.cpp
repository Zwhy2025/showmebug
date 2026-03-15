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
        vector<vector<int>> expected{{7,4,1},{8,5,2},{9,6,3}};
        s.rotate(matrix);
        checkEqual("sample-1", matrix, expected);
    }

    {
        vector<vector<int>> matrix{{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        vector<vector<int>> expected{{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
        s.rotate(matrix);
        checkEqual("sample-2", matrix, expected);
    }

    return 0;
}
