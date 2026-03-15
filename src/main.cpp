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
        vector<int> nums{2,3,1,1,4};
        checkEqual("sample-1", s.jump(nums), 2);
    }

    {
        vector<int> nums{2,3,0,1,4};
        checkEqual("sample-2", s.jump(nums), 2);
    }

    return 0;
}
