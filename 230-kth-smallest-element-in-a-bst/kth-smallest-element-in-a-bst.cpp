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
    int prevorder = 0;
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) {
            return -1;
        }
        if (root->left != NULL) {
            int leftsm = kthSmallest(root->left, k);
            if (leftsm != -1) {
                return leftsm;
            }
        }
        if (prevorder + 1 == k) {
            return root->val;
        }
        prevorder = prevorder + 1;
        if (root->right != NULL) {
            int rightsm = kthSmallest(root->right, k);
            if (rightsm != -1) {
                return rightsm;
            }
        }
        return -1;
    }
};