#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#include "solution.hpp"

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


ListNode *buildList(const vector<int> &values) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

ListNode *buildCycleList(const vector<int> &values, int pos) {
    ListNode *head = buildList(values);
    if (head == nullptr || pos < 0) {
        return head;
    }

    ListNode *tail = head;
    ListNode *entry = nullptr;
    int index = 0;
    for (ListNode *node = head; node != nullptr; node = node->next, ++index) {
        if (index == pos) {
            entry = node;
        }
        tail = node;
    }
    if (tail != nullptr && entry != nullptr) {
        tail->next = entry;
    }
    return head;
}

void freeList(ListNode *head) {
    unordered_set<ListNode *> visited;
    ListNode *node = head;
    while (node != nullptr && !visited.count(node)) {
        visited.insert(node);
        ListNode *next = node->next;
        delete node;
        node = next;
    }
}


int main() {
    Solution s;

    {
        ListNode *head = buildCycleList({3, 2, 0, -4}, 1);
        bool expected = true;
        auto actual = s.hasCycle(head);
        checkEqual("sample-1", actual, expected);
        freeList(head);
    }

    {
        ListNode *head = buildCycleList({1, 2}, 0);
        bool expected = true;
        auto actual = s.hasCycle(head);
        checkEqual("sample-2", actual, expected);
        freeList(head);
    }

    {
        ListNode *head = buildCycleList({1}, -1);
        bool expected = false;
        auto actual = s.hasCycle(head);
        checkEqual("sample-3", actual, expected);
        freeList(head);
    }

    {
        ListNode *head = buildCycleList({1}, 0);
        bool expected = true;
        auto actual = s.hasCycle(head);
        checkEqual("sample-4", actual, expected);
        freeList(head);
    }

    return 0;
}
