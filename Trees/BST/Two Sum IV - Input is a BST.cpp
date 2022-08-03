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
    
    void inorder(TreeNode *root, vector<int> &ds)
    {
        if(!root)
            return;
        
        inorder(root->left, ds);
        ds.push_back(root->val);
        inorder(root->right, ds);
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> ds;
        
        inorder(root, ds);
        
        int i = 0, j = ds.size() - 1, sum = 0;
        
        while(i < j)
        {
            sum = ds[i] + ds[j];
            if(sum == k)
                return true;
            else if(sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};