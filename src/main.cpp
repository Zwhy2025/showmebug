#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 合并两个有序链表
// https://leetcode.cn/problems/merge-two-sorted-lists/

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


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    ListNode* list1 = buildList({/* TODO */});
    ListNode* list2 = buildList({/* TODO */});
        vector<int> expected{/* TODO */};
        auto actual = s.mergeTwoLists(list1, list2);
        checkEqual("sample-1", listToVector(actual), expected);
    }

    return 0;
}
