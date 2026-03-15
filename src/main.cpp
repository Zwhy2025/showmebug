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
        vector<int> expected{9,7,8};
        auto actual = s.partitionLabels("ababcbacadefegdehijhklij");
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> expected{10};
        auto actual = s.partitionLabels("eccbbbbdec");
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
