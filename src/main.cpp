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

// Build a random list from pairs: {val, random_index} where -1 means null
Node *buildRandomList(const vector<pair<int,int>> &values) {
    vector<Node*> nodes;
    for (auto &[v, _] : values) nodes.push_back(new Node(v));
    for (int i = 0; i < (int)nodes.size(); i++) {
        if (i + 1 < (int)nodes.size()) nodes[i]->next = nodes[i+1];
        if (values[i].second >= 0) nodes[i]->random = nodes[values[i].second];
    }
    return nodes.empty() ? nullptr : nodes[0];
}

bool verifyDeepCopy(Node *original, Node *copied) {
    // Collect original nodes for identity check
    unordered_set<Node*> origNodes;
    for (Node *n = original; n; n = n->next) origNodes.insert(n);

    Node *o = original, *c = copied;
    while (o && c) {
        if (o->val != c->val) return false;
        if (origNodes.count(c)) return false; // must be a new node
        if ((o->random == nullptr) != (c->random == nullptr)) return false;
        if (o->random && c->random && o->random->val != c->random->val) return false;
        o = o->next;
        c = c->next;
    }
    return o == nullptr && c == nullptr;
}

int main() {
    Solution s;

    {
        Node *head = buildRandomList({{7,-1},{13,0},{11,4},{10,2},{1,0}});
        Node *copy = s.copyRandomList(head);
        checkEqual("sample-1", verifyDeepCopy(head, copy), true);
    }

    {
        Node *head = buildRandomList({{1,1},{2,1}});
        Node *copy = s.copyRandomList(head);
        checkEqual("sample-2", verifyDeepCopy(head, copy), true);
    }

    {
        Node *head = buildRandomList({{3,-1},{3,0},{3,-1}});
        Node *copy = s.copyRandomList(head);
        checkEqual("sample-3", verifyDeepCopy(head, copy), true);
    }

    return 0;
}
