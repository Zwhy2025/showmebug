#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 字母异位词分组
// https://leetcode.cn/problems/group-anagrams/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    vector<string> strs{/* TODO */};
        vector<vector<string>> expected{/* TODO */};
        auto actual = s.groupAnagrams(strs);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
