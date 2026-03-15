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

// 买卖股票的最佳时机
// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int min = INT_MAX;
        int max = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            min = std::min(prices[i], min);
            max = std::max(prices[i] - min, max);
        }
        return max;
    }
};
