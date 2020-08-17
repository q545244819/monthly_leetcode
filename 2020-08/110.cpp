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
    bool res = true;
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        dfs(root);
        return res;
    }

    int dfs (TreeNode* root) {
        if (root == NULL) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (abs(left - right) > 1)
            res = false;
        
        return 1 + max(left, right);
    }
};