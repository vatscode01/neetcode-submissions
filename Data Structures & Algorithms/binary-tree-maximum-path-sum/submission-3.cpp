/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    // Self
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        res = max(res, func(root, res));
        return res;
    }
    int func(TreeNode* root, int& res) {
        if (!root) return 0;

        int l = func(root->left, res);
        int r = func(root->right, res);

        res = max({res, root->val + max({0,l,r}), root->val + l + r});

        return root->val + max({0,l,r});
    }
};
