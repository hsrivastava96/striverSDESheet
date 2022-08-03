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
    check if both are NULL 
        => if yes, return true
    else check if either are NULL
        => if yes, return false
    check if values are not same
        => if yes, return false

    check left sub tree for both
    check right sub tree for both

    perform boolean and on left and right and return the result
    because if both the left sub trees and ruight sub trees are same 
    along with root's values then only the trees are same
 */


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL && q != NULL)
            return false;
        else if(p != NULL && q == NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);
        
        return l&&r;
    }
};