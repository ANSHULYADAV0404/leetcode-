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
    vector<int> ans;
    int maxcount = 0;
    int currcount = 0;
    int currval = 0;
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        if (root->val == currval) {
            currcount++;
        } else {
            currval = root->val;
            currcount = 1;
        }
        if (currcount > maxcount) {
            maxcount = currcount;
            ans.clear();
            ans.push_back(currval);
        } else if (currcount == maxcount) {
            ans.push_back(currval);
        }

        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {

        inorder(root);
        return ans;
    }
};