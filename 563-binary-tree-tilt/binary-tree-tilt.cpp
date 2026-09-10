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
    int maxsum = 0;
    int sum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = sum(root->left);
        int right = sum(root->right);
        maxsum += abs(left - right);
        return root->val + left + right;
    }
    int findTilt(TreeNode* root) {
        sum(root);
         //maxsum = 0;
        return maxsum;
    }
};