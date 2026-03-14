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
    template <typename T>
    void printVector(const std::vector<T> &nums, const std::string &name = "nums") {
        std::cout << name << ": ";
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (i)
                std::cout << ' ';
            std::cout << nums[i];
        }
        std::cout << '\n';
    }
    void moveZeroes(vector<int> &nums) {
        int it = 0, that = it;
        printVector(nums, "1");

        for (; it < nums.size();) {
            if (nums[it] != 0) {
                nums[that] = nums[it];
                that++;
            }
            it++;
        }

        printVector(nums, "2");
        for (int i = nums.size() - 1; i > nums.size() - 1 - (it - that); --i) {
            nums[i] = 0;
        }
        printVector(nums, "3");
    }
};
