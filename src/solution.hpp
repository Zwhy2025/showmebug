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
            std::cout << " " << nums[i];
        }
        std::cout << std::endl;
        int sut = 0;
        for (int i = 0; i < nums.size();) {
            if (i == nums.size() - 1 - sut) {
                std::cout << "end nums: ";
                for (int i = 0; i < nums.size(); ++i) {
                    std::cout << " " << nums[i];
                }
                std::cout << std::endl;
                return;
            }

            if (nums[i] == 0) {
                for (int j = i; j < nums.size() - 1; ++j) {
                    nums[j] = nums[j + 1];
                }
                nums[nums.size() - 1 - sut] = 0;
                sut++;
            } else {
                i++;
            }
        }
    }
};
