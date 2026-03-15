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
        ListNode *l1 = buildList({2,4,3});
        ListNode *l2 = buildList({5,6,4});
        vector<int> expected{7,0,8};
        ListNode *result = s.addTwoNumbers(l1, l2);
        checkEqual("sample-1", listToVector(result), expected);
        freeList(result);
    }

    {
        ListNode *l1 = buildList({0});
        ListNode *l2 = buildList({0});
        vector<int> expected{0};
        ListNode *result = s.addTwoNumbers(l1, l2);
        checkEqual("sample-2", listToVector(result), expected);
        freeList(result);
    }

    {
        ListNode *l1 = buildList({9,9,9,9,9,9,9});
        ListNode *l2 = buildList({9,9,9,9});
        vector<int> expected{8,9,9,9,0,0,0,1};
        ListNode *result = s.addTwoNumbers(l1, l2);
        checkEqual("sample-3", listToVector(result), expected);
        freeList(result);
    }

    return 0;
}
