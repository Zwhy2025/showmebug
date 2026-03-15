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
        string str = "leetcode";
        vector<string> dict{"leet","code"};
        checkEqual("sample-1", s.wordBreak(str, dict), true);
    }

    {
        string str = "applepenapple";
        vector<string> dict{"apple","pen"};
        checkEqual("sample-2", s.wordBreak(str, dict), true);
    }

    {
        string str = "catsandog";
        vector<string> dict{"cats","dog","sand","and","cat"};
        checkEqual("sample-3", s.wordBreak(str, dict), false);
    }

    return 0;
}
