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
        vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
        vector<vector<int>> expected{{1,6},{8,10},{15,18}};
        auto actual = s.merge(intervals);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<vector<int>> intervals{{1,4},{4,5}};
        vector<vector<int>> expected{{1,5}};
        auto actual = s.merge(intervals);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
