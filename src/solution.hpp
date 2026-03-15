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

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {

        int max_val = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {

            for (int j = i + 1; j <= nums.size(); ++j) {

                auto val = std::accumulate(nums.begin() + i, nums.begin() + j, 0);

                max_val = (val > max_val) ? val : max_val;
            }
        }
        return max_val;
    }
};
