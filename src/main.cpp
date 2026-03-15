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

void freeTree(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}


int main() {
    Solution s;

    {
        TreeNode *root = buildTree({3, 9, 20, nullopt, nullopt, 15, 7});
        int expected = 3;
        auto actual = s.maxDepth(root);
        checkEqual("sample-1", actual, expected);
        freeTree(root);
    }

    {
        TreeNode *root = buildTree({1, nullopt, 2});
        int expected = 2;
        auto actual = s.maxDepth(root);
        checkEqual("sample-2", actual, expected);
        freeTree(root);
    }

    {
        TreeNode *root = buildTree({});
        int expected = 0;
        auto actual = s.maxDepth(root);
        checkEqual("sample-3", actual, expected);
        freeTree(root);
    }

    {
        TreeNode *root = buildTree({1});
        int expected = 1;
        auto actual = s.maxDepth(root);
        checkEqual("sample-4", actual, expected);
        freeTree(root);
    }

    return 0;
}
