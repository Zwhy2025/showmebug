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
        auto actual = s.letterCombinations("23");
        sort(actual.begin(), actual.end());
        vector<string> expected{"ad","ae","af","bd","be","bf","cd","ce","cf"};
        checkEqual("sample-1", actual, expected);
    }

    {
        auto actual = s.letterCombinations("");
        vector<string> expected{};
        checkEqual("sample-2", actual, expected);
    }

    {
        auto actual = s.letterCombinations("2");
        sort(actual.begin(), actual.end());
        vector<string> expected{"a","b","c"};
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
