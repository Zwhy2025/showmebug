#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 最小栈
// https://leetcode.cn/problems/min-stack/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


int main() {
    // TODO: add operation-based tests for MinStack.
    // Example:
    // MinStack obj(/* TODO */);
    // auto actual = obj.someMethod(/* TODO */);
    // int expected = 0;
    // checkEqual("sample-1", actual, expected);
    cout << "Edit src/main.cpp to add operation-based tests." << '\n';
    return 0;
}
