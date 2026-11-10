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
    int goodNodes(TreeNode* root) {
        return func(root,INT_MIN);
    }
    int func(TreeNode* root, int num){
        if(!root)   return 0;
        int maxi = max(root->val, num);

        return (root->val >= num) + func(root->left, maxi) + func(root->right, maxi);
    }
};
