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
        vector<vector<int>> expected{{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
        auto actual = s.generate(5);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<vector<int>> expected{{1}};
        auto actual = s.generate(1);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
