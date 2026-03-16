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

// 二叉树的层序遍历
// https://leetcode.cn/problems/binary-tree-level-order-traversal/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ret{};
        std::queue<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            vector<int> vec;
            int num_size = stk.size();

            for (int i = 0; i < num_size; ++i) {
                auto node = stk.front();
                stk.pop();
                vec.push_back(node->val);

                // push
                if (node->left)
                    stk.push(node->left);
                if (node->right)
                    stk.push(node->right);
            }
            ret.push_back(vec);
        }
        return ret;
    }

    /*
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> ret;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode *node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            ret.push_back(level);
        }

        return ret;
    }
    */
};
