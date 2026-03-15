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
    Solution solver;

    {
        string input = "abcabcbb";
        int expected = 3;
        auto actual = solver.lengthOfLongestSubstring(input);
        checkEqual("sample-1", actual, expected);
    }

    {
        string input = "bbbbb";
        int expected = 1;
        auto actual = solver.lengthOfLongestSubstring(input);
        checkEqual("sample-2", actual, expected);
    }

    {
        string input = "pwwkew";
        int expected = 3;
        auto actual = solver.lengthOfLongestSubstring(input);
        checkEqual("sample-3", actual, expected);
    }

    {
        string input = "";
        int expected = 0;
        auto actual = solver.lengthOfLongestSubstring(input);
        checkEqual("sample-4", actual, expected);
    }

    {
        string input = " ";
        int expected = 1;
        auto actual = solver.lengthOfLongestSubstring(input);
        checkEqual("sample-5", actual, expected);
    }

    return 0;
}
