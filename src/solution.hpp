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

class Solution {
  public:
    bool isRepeat(string str) {
        std::set<char> set;
        for (auto s : str) {
            set.insert(s);
        }
        return set.size() < str.size(); // true = 有重复;
    }

    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0; // 加这一行
        int max_val = 1;
        int slow = 0;
        for (int fast = 1; fast < s.size(); ++fast) {
            while (isRepeat(s.substr(slow, fast - slow + 1))) {
                slow++;
            }

            max_val = std::max(fast - slow + 1, max_val);
        }

        return max_val;
    }
};
