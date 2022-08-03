/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 
TreeNode * getPath(TreeNode *root, int B, vector<int> &ds)
{
    if(!root)
        return NULL;
    
    ds.push_back(root->val);

    if(root->val == B)
        return root;
    
    TreeNode *l = getPath(root->left, B, ds);
    TreeNode *r = getPath(root->right, B, ds);
    
    if(l == NULL && r == NULL)
    {
        ds.pop_back();
        return NULL;
    }
    else if(l == NULL && r != NULL)
        return r;
    else
        return l;
    
}
vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int> ds;
    getPath(A, B, ds);
    return ds;
}
