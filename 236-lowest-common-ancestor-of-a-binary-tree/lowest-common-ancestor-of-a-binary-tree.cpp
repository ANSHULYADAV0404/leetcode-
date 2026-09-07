/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return 0;
        }
        if (root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode* leftlcm = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightlcm = lowestCommonAncestor(root->right, p, q);
        if (leftlcm && rightlcm) {
            return root;
        }
        else if(leftlcm != NULL) { return leftlcm; }
        else {
            return rightlcm;
        }
    }
};