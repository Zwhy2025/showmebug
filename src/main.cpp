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
        vector<vector<int>> prereqs{{1,0}};
        checkEqual("sample-1", s.canFinish(2, prereqs), true);
    }

    {
        vector<vector<int>> prereqs{{1,0},{0,1}};
        checkEqual("sample-2", s.canFinish(2, prereqs), false);
    }

    return 0;
}
