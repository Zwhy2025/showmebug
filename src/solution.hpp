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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
  public:
    bool isPalindrome(ListNode *head) {

        auto it = head;
        std::vector<int> nums;
        while (it != nullptr) {
            nums.push_back(it->val);
            it = it->next;
        }

        for (int i = 0, j = nums.size() - 1; i <= nums.size() / 2; ++i, j--) {
            if (nums[i] != nums[j]) {
                return false;
            }
        }
        return true;
    }
};
