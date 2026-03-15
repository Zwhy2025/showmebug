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
        vector<int> nums1{1,3}, nums2{2};
        checkEqual("sample-1", s.findMedianSortedArrays(nums1, nums2), 2.0);
    }

    {
        vector<int> nums1{1,2}, nums2{3,4};
        checkEqual("sample-2", s.findMedianSortedArrays(nums1, nums2), 2.5);
    }

    return 0;
}
