#pragma once

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <exception>
#include <functional>
#include <limits>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// 有效的括号
// https://leetcode.cn/problems/valid-parentheses/
class Solution {
  public:
    char CP(char c) {
        if (c == '(') {
            return ')';
        } else if (c == '[') {
            return ']';
        } else if (c == '{') {
            return '}';
        } else {
            return '0';
        }
    }

    bool isValid(string s) {

        std::stack<char> stc;
        for (auto &c : s) {
            auto val = '1';
            if (!stc.empty()) {
                val = CP(stc.top());
            }
            if (!stc.empty() && val == c) {
                stc.pop();
            } else if (val == '0') {
                stc.push(c);
            } else {
                stc.push(c);
            }
        }
        return stc.empty();
    }

    /*
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<char> stc;
        for (char c : s) {
            if (c == '(') {
                stc.push(')');
            } else if (c == '[') {
                stc.push(']');
            } else if (c == '{') {
                stc.push('}');
            } else {
                if (stc.empty() || stc.top() != c) {
                    return false;
                }
                stc.pop();
            }
        }

        return stc.empty();
    }
    */
};
