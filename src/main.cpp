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
        // TODO: replace the placeholders below with a real sample.
    int numCourses = 0;
    vector<vector<int>> prerequisites{/* TODO */};
        bool expected = false;
        auto actual = s.canFinish(numCourses, prerequisites);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
