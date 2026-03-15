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
        Trie trie;
        trie.insert("apple");
        checkEqual("search-apple", trie.search("apple"), true);
        checkEqual("search-app", trie.search("app"), false);
        checkEqual("startsWith-app", trie.startsWith("app"), true);
        trie.insert("app");
        checkEqual("search-app-2", trie.search("app"), true);
    }

    return 0;
}
