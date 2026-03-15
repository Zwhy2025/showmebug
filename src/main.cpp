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
    {
        MedianFinder mf;
        mf.addNum(1);
        mf.addNum(2);
        checkEqual("median-1", mf.findMedian(), 1.5);
        mf.addNum(3);
        checkEqual("median-2", mf.findMedian(), 2.0);
    }

    return 0;
}
