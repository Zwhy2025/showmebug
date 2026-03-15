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
        LRUCache cache(2);
        cache.put(1, 1);
        cache.put(2, 2);
        checkEqual("get-1", cache.get(1), 1);
        cache.put(3, 3);  // evicts key 2
        checkEqual("get-2-evicted", cache.get(2), -1);
        cache.put(4, 4);  // evicts key 1
        checkEqual("get-1-evicted", cache.get(1), -1);
        checkEqual("get-3", cache.get(3), 3);
        checkEqual("get-4", cache.get(4), 4);
    }

    return 0;
}
