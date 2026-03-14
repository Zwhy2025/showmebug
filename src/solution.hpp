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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    bool hasCycle(ListNode *head) {

        if (!head || !head->next) {
            return false;
        }
        auto start = head->next;
        auto end = head;

        while (start != end) {
            if (!start || !end) {
                return false;
            }
            if (!start->next || !start->next->next) {
                return false;
            }

            if (!end->next) {
                return false;
            }

            start = start->next->next;
            end = end->next;
        }
        return true;
    }
};
