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

    void preOrder(TreeNode *root, vector<int> &ds)
    {
        if(!root)
            return;
        
        ds.push_back(root->val);
        preOrder(root->left, ds);
        preOrder(root->right, ds);
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> ds;
        preOrder(root, ds);
        return ds;
    }
};