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
    int sum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        // int left = sum(root->left);
        // int right = sum(root->right);
        return 1 + max(sum(root->left), sum(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int left = sum(root->left);
        int right = sum(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) &&
               isBalanced(root->right);
    }
};