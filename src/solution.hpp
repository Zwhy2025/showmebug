#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
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

// 最大子数组和
// https://leetcode.cn/problems/maximum-subarray/
class Solution {
  public:
    int maxSubArray(vector<int> &nums) {

        int dp_1 = nums[0], max_val = nums[0];
        for (int i = 1; i < nums.size(); ++i) {

            auto cur = std::max(nums[i], dp_1 + nums[i]);

            max_val = std::max(cur, max_val);
            dp_1 = cur;
        }
        return max_val;
    }
};
