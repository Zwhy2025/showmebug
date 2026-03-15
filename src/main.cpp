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

#include <algorithm>

int main() {
    Solution s;

    {
        auto actual = s.partition("aab");
        sort(actual.begin(), actual.end());
        vector<vector<string>> expected{{"a","a","b"},{"aa","b"}};
        sort(expected.begin(), expected.end());
        checkEqual("sample-1", actual, expected);
    }

    {
        auto actual = s.partition("a");
        vector<vector<string>> expected{{"a"}};
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
