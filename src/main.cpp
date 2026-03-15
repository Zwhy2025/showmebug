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
        string str = "cbaebabacd", p = "abc";
        vector<int> expected{0, 6};
        auto actual = s.findAnagrams(str, p);
        checkEqual("sample-1", actual, expected);
    }

    {
        string str = "abab", p = "ab";
        vector<int> expected{0, 1, 2};
        auto actual = s.findAnagrams(str, p);
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
