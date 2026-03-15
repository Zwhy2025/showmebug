#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include <unordered_set>

#include "solution.hpp"

ListNode *buildList(const vector<int> &values) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

vector<int> listToVector(ListNode *head) {
    vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

void freeList(ListNode *head) {
    while (head != nullptr) {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}

int main() {
    Solution s;

    {
        ListNode *head = buildList({4,2,1,3});
        vector<int> expected{1,2,3,4};
        ListNode *result = s.sortList(head);
        checkEqual("sample-1", listToVector(result), expected);
        freeList(result);
    }

    {
        ListNode *head = buildList({-1,5,3,4,0});
        vector<int> expected{-1,0,3,4,5};
        ListNode *result = s.sortList(head);
        checkEqual("sample-2", listToVector(result), expected);
        freeList(result);
    }

    {
        ListNode *head = buildList({});
        vector<int> expected{};
        ListNode *result = s.sortList(head);
        checkEqual("sample-3", listToVector(result), expected);
        freeList(result);
    }

    return 0;
}
