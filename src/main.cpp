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
    Node* head = nullptr;
        auto actual = s.copyRandomList(head);
        (void)actual;
        cout << "sample-1: executed (TODO: add expected check for Node*)" << '\n';
    }

    return 0;
}
