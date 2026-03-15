#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// 环形链表
// https://leetcode.cn/problems/linked-list-cycle/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *start = head->next;
        ListNode *end = head;

        // start 每次走两步，end 每次走一步。
        // 如果链表有环，两者最终会在环内相遇。
        while (start != end) {
            // 任一指针走到空，说明链表无环。
            if (start == nullptr || end == nullptr) {
                return false;
            }

            // start 还要再走两步，所以需要提前判断后继是否存在。
            if (start->next == nullptr || start->next->next == nullptr) {
                return false;
            }

            if (end->next == nullptr) {
                return false;
            }

            start = start->next->next;
            end = end->next;
        }

        return true;
    }

    /*
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // slow 每次走一步，fast 每次走两步。
        // 如果链表中存在环，fast 最终会在环内追上 slow。
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            // 指针相遇，说明链表有环。
            if (slow == fast) {
                return true;
            }
        }

        // fast 提前走到空，说明链表无环。
        return false;
    }
    */
};
