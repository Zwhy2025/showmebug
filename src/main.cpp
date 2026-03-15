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

    checkEqual("sample-1", s.decodeString("3[a]2[bc]"), string("aaabcbc"));
    checkEqual("sample-2", s.decodeString("3[a2[c]]"), string("accaccacc"));
    checkEqual("sample-3", s.decodeString("2[abc]3[cd]ef"), string("abcabccdcdcdef"));

    return 0;
}
