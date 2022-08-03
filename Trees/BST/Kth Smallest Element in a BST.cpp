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
    keep a counter
    start inorder traversal (because in inorder traversal BST is in sorted order)
    when count == k
    set ans to root->val

 */
class Solution {
public:
    
    void getKSmall(TreeNode *root, int k, int &count, int &ans)
    {
        if(!root)
            return;
        
        getKSmall(root->left, k, count, ans);
        count++;
        if(count == k)
            ans = root->val;
        getKSmall(root->right, k, count, ans);
        
    }
    
    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = 0, count = 0;
        getKSmall(root, k, count, ans);
        return ans;
    }
};