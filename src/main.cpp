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
        string str = "ADOBECODEBANC", t = "ABC";
        string expected = "BANC";
        auto actual = s.minWindow(str, t);
        checkEqual("sample-1", actual, expected);
    }

    {
        string str = "a", t = "a";
        string expected = "a";
        auto actual = s.minWindow(str, t);
        checkEqual("sample-2", actual, expected);
    }

    {
        string str = "a", t = "aa";
        string expected = "";
        auto actual = s.minWindow(str, t);
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
