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
        TreeNode *root = buildTree({3, 9, 20, nullopt, nullopt, 15, 7});
        vector<vector<int>> expected{{3},{9,20},{15,7}};
        auto actual = s.levelOrder(root);
        checkEqual("sample-1", actual, expected);
    }

    {
        TreeNode *root = buildTree({1});
        vector<vector<int>> expected{{1}};
        auto actual = s.levelOrder(root);
        checkEqual("sample-2", actual, expected);
    }

    {
        TreeNode *root = buildTree({});
        vector<vector<int>> expected{};
        auto actual = s.levelOrder(root);
        checkEqual("sample-3", actual, expected);
    }

    return 0;
}
