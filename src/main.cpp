#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 两两交换链表中的节点
// https://leetcode.cn/problems/swap-nodes-in-pairs/

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
    ListNode* head = buildList({/* TODO */});
        vector<int> expected{/* TODO */};
        auto actual = s.swapPairs(head);
        checkEqual("sample-1", listToVector(actual), expected);
    }

    return 0;
}
