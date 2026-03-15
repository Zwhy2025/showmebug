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
        vector<ListNode*> lists{buildList({1,4,5}), buildList({1,3,4}), buildList({2,6})};
        vector<int> expected{1,1,2,3,4,4,5,6};
        ListNode *result = s.mergeKLists(lists);
        checkEqual("sample-1", listToVector(result), expected);
        freeList(result);
    }

    {
        vector<ListNode*> lists{};
        vector<int> expected{};
        ListNode *result = s.mergeKLists(lists);
        checkEqual("sample-2", listToVector(result), expected);
        freeList(result);
    }

    {
        vector<ListNode*> lists{buildList({})};
        vector<int> expected{};
        ListNode *result = s.mergeKLists(lists);
        checkEqual("sample-3", listToVector(result), expected);
        freeList(result);
    }

    return 0;
}
