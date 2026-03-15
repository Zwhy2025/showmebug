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
        vector<string> strs{"eat","tea","tan","ate","nat","bat"};
        auto actual = s.groupAnagrams(strs);
        // sort each group and sort groups for comparison
        for (auto &g : actual) sort(g.begin(), g.end());
        sort(actual.begin(), actual.end());
        vector<vector<string>> expected{{"ate","eat","tea"},{"bat"},{"nat","tan"}};
        for (auto &g : expected) sort(g.begin(), g.end());
        sort(expected.begin(), expected.end());
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<string> strs{""};
        auto actual = s.groupAnagrams(strs);
        vector<vector<string>> expected{{""}};
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<string> strs{"a"};
        auto actual = s.groupAnagrams(strs);
        vector<vector<string>> expected{{"a"}};
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
