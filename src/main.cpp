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

    checkEqual("sample-1", s.uniquePaths(3, 7), 28);
    checkEqual("sample-2", s.uniquePaths(3, 2), 3);

    return 0;
}
