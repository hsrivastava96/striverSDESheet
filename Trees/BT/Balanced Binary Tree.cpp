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

    Algo:
    Find height of left sub tree and right sub tree for each node
    Compare if absolute difference between the heights is 0, 1, or greater than 1
    if the absolute difference is greater than 1 then set flag = 1

    if at the end of all the comparisons the flag = 1
    then return false (Means the tree is not height balanced)
    otherwise return true (Means the tree is height balanced)
 */
class Solution {
public:
    
    int findHeight(TreeNode *root, int &flag)
    {
        if(!root)
            return 0;
        
        int l = findHeight(root->left, flag);
        int r = findHeight(root->right, flag);
        
        if(abs(l-r) > 1)
            flag = 1;
        
        if(l == 0 && r == 0)
            return 1;
        else
        {
            if(l > r)
                return l + 1;
            return r + 1;
        }
    }
    
    bool isBalanced(TreeNode* root) 
    {
        int flag = 0;
        
        findHeight(root, flag);
        if(flag == 1)
            return false;
        return true;
    }
};