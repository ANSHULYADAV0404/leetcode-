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
    void solve(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }
        if (root->left != NULL) {
            solve(root->left, ans);
            // ans.push_back(root->left)
        }
        if (root->val != NULL) {
            ans.push_back(root->val);
        }
        if (root->right != NULL) {
          solve(root->right, ans);
        }
    }
    TreeNode* build(vector<int>& ans, int lp, int rp) {
        if (lp > rp) {
            return NULL;
        }
        int mid = lp + (rp - lp) / 2;
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = build(ans, lp, mid - 1);
        root->right = build(ans, mid + 1, rp);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return build(ans, 0, ans.size()-1);
    }
};