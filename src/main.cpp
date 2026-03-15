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
        MinStack ms;
        ms.push(-2);
        ms.push(0);
        ms.push(-3);
        checkEqual("getMin-1", ms.getMin(), -3);
        ms.pop();
        checkEqual("top-1", ms.top(), 0);
        checkEqual("getMin-2", ms.getMin(), -2);
    }

    return 0;
}
