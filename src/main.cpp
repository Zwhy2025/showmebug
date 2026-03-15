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

// Verify BST property and balance
bool isBST(TreeNode *root, long lo, long hi) {
    if (!root) return true;
    if (root->val <= lo || root->val >= hi) return false;
    return isBST(root->left, lo, root->val) && isBST(root->right, root->val, hi);
}

int getHeight(TreeNode *root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

bool isBalanced(TreeNode *root) {
    if (!root) return true;
    int lh = getHeight(root->left), rh = getHeight(root->right);
    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int main() {
    Solution s;

    {
        vector<int> nums{-10, -3, 0, 5, 9};
        TreeNode *root = s.sortedArrayToBST(nums);
        checkEqual("sample-1-bst", isBST(root, LONG_MIN, LONG_MAX), true);
        checkEqual("sample-1-balanced", isBalanced(root), true);
    }

    {
        vector<int> nums{1, 3};
        TreeNode *root = s.sortedArrayToBST(nums);
        checkEqual("sample-2-bst", isBST(root, LONG_MIN, LONG_MAX), true);
        checkEqual("sample-2-balanced", isBalanced(root), true);
    }

    return 0;
}
