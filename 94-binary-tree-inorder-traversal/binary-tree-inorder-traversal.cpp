/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;

        helper(root->left, ans);  // 1. Visit Left Subtree
        ans.push_back(root->val); // 2. Visit Current Node
        helper(root->right, ans); // 3. Visit Right Subtree
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
         helper(root, ans);
        return ans;
    }
};