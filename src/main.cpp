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
        vector<int> nums{1,1,1,2,2,3};
        auto actual = s.topKFrequent(nums, 2);
        sort(actual.begin(), actual.end());
        vector<int> expected{1,2};
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> nums{1};
        auto actual = s.topKFrequent(nums, 1);
        vector<int> expected{1};
        checkEqual("sample-2", actual, expected);
    }

    return 0;
}
