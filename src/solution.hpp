#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <ios>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <ostream>
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
    void moveZeroes(vector<int> &nums) {
        std::cout << "\n before nums: ";
        for (int i = 0; i < nums.size(); ++i) {
            std::cout << " " << i;
        }
        std::cout << std::endl;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                for (int j = i; j < nums.size(); ++j) {
                    nums[j] = nums[j + 1];
                }
                nums[nums.size() - 1 - i] = 0;
            }
        }

        std::cout << "end nums: ";
        for (int i = 0; i < nums.size(); ++i) {
            std::cout << " " << i;
        }
        std::cout << std::endl;
    }
};
