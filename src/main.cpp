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
        vector<int> nums{3,2,1,5,6,4};
        checkEqual("sample-1", s.findKthLargest(nums, 2), 5);
    }

    {
        vector<int> nums{3,2,3,1,2,4,5,5,6};
        checkEqual("sample-2", s.findKthLargest(nums, 4), 4);
    }

    return 0;
}
