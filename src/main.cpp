#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "solution.hpp"

template <typename T>
void checkEqual(const string &caseName, const T &actual, const T &expected) {
    bool pass = actual == expected;
    cout << caseName << ": " << (pass ? "PASS" : "FAIL") << '\n';
}


TreeNode *buildTree(const vector<optional<int>> &values) {
    if (values.empty() || !values[0].has_value()) return nullptr;
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
    if (!root) return {};
    vector<optional<int>> values;
    queue<TreeNode *> nodes;
    nodes.push(root);
    while (!nodes.empty()) {
        TreeNode *cur = nodes.front(); nodes.pop();
        if (!cur) { values.push_back(nullopt); continue; }
        values.push_back(cur->val);
        nodes.push(cur->left);
        nodes.push(cur->right);
    }
    while (!values.empty() && !values.back().has_value()) values.pop_back();
    return values;
}

TreeNode *findNode(TreeNode *root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode *l = findNode(root->left, val);
    if (l) return l;
    return findNode(root->right, val);
}

int main() {
    Solution s;

    {
        TreeNode *root = buildTree({4, 2, 7, 1, 3, 6, 9});
        vector<optional<int>> expected{4, 7, 2, 9, 6, 3, 1};
        TreeNode *result = s.invertTree(root);
        checkEqual("sample-1", treeToLevelOrder(result), expected);
    }

    {
        TreeNode *root = buildTree({2, 1, 3});
        vector<optional<int>> expected{2, 3, 1};
        TreeNode *result = s.invertTree(root);
        checkEqual("sample-2", treeToLevelOrder(result), expected);
    }

    {
        TreeNode *root = buildTree({});
        vector<optional<int>> expected{};
        TreeNode *result = s.invertTree(root);
        checkEqual("sample-3", treeToLevelOrder(result), expected);
    }

    return 0;
}
