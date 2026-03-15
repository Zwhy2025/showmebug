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
        vector<int> temps{73,74,75,71,69,72,76,73};
        vector<int> expected{1,1,4,2,1,1,0,0};
        auto actual = s.dailyTemperatures(temps);
        checkEqual("sample-1", actual, expected);
    }

    {
        vector<int> temps{30,40,50,60};
        vector<int> expected{1,1,1,0};
        auto actual = s.dailyTemperatures(temps);
        checkEqual("sample-2", actual, expected);
    }

    {
        vector<int> temps{30,60,90};
        vector<int> expected{1,1,0};
        auto actual = s.dailyTemperatures(temps);
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
