#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 回文链表
// https://leetcode.cn/problems/palindrome-linked-list/

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

vector<int> listToVector(ListNode *head) {
    vector<int> values;
    for (ListNode *node = head; node != nullptr; node = node->next) {
        values.push_back(node->val);
    }
    return values;
}

void freeList(ListNode *head) {
    while (head != nullptr) {
        ListNode *next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    Solution s;

    {
        ListNode *head = buildList({1, 2, 2, 1});
        bool expected = true;
        auto actual = s.isPalindrome(head);
        checkEqual("sample-1", actual, expected);
        freeList(head);
    }

    {
        ListNode *head = buildList({1, 2});
        bool expected = false;
        auto actual = s.isPalindrome(head);
        checkEqual("sample-2", actual, expected);
        freeList(head);
    }

    {
        ListNode *head = buildList({1, 2, 3, 2, 1});
        bool expected = true;
        auto actual = s.isPalindrome(head);
        checkEqual("sample-3", actual, expected);
        freeList(head);
    }

    return 0;
}
