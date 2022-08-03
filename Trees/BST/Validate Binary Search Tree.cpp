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
    
    bool check(vector<int> &ds)
    {
        int n = ds.size();
        
        for(int i = 0; i < n-1; i++)
        {
            if(ds[i] >= ds[i+1])
                return false;
        }
        return true;
        
    }
    
    bool isValidBST(TreeNode* root) 
    {
        if(!root)
            return true;    
        
        vector<int> ds;
        inorder(root, ds);
        
        return check(ds);
    }
};