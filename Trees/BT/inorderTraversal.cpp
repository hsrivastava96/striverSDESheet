    void inorder(TreeNode *root, vector<int> &ds)
    {
        if(!root)
            return;
        
        inorder(root->left, ds);
        ds.push_back(root->val);
        inorder(root->right, ds);
    }
    
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> ds;
        inorder(root, ds);
        return ds;
    }
