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
        auto actual = s.longestPalindrome("babad");
        bool ok = actual == "bab" || actual == "aba";
        checkEqual("sample-1", ok, true);
    }

    checkEqual("sample-2", s.longestPalindrome("cbbd"), string("bb"));

    return 0;
}
