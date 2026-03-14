#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

// 对称二叉树
// https://leetcode.cn/problems/symmetric-tree/

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


TreeNode *buildTree(const vector<optional<int>> &values) {
    if (values.empty() || !values[0].has_value()) {
        return nullptr;
    }

    TreeNode *root = new TreeNode(*values[0]);
    queue<TreeNode *> nodes;
    nodes.push(root);

    size_t index = 1;
    while (!nodes.empty() && index < values.size()) {
        TreeNode *current = nodes.front();
        nodes.pop();

        if (index < values.size() && values[index].has_value()) {
            current->left = new TreeNode(*values[index]);
            nodes.push(current->left);
        }
        ++index;

        if (index < values.size() && values[index].has_value()) {
            current->right = new TreeNode(*values[index]);
            nodes.push(current->right);
        }
        ++index;
    }

    return root;
}

vector<optional<int>> treeToLevelOrder(TreeNode *root) {
    if (root == nullptr) {
        return {};
    }

    vector<optional<int>> values;
    queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
        TreeNode *current = nodes.front();
        nodes.pop();

        if (current == nullptr) {
            values.push_back(nullopt);
            continue;
        }

        values.push_back(current->val);
        nodes.push(current->left);
        nodes.push(current->right);
    }

    while (!values.empty() && !values.back().has_value()) {
        values.pop_back();
    }

    return values;
}


int main() {
    Solution s;

    {
        // TODO: replace the placeholders below with a real sample.
    TreeNode* root = buildTree({/* TODO: level-order, use nullopt for empty */});
        bool expected = false;
        auto actual = s.isSymmetric(root);
        checkEqual("sample-1", actual, expected);
    }

    return 0;
}
