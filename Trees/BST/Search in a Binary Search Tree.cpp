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
    store root in temp node
    check if temp node is null and temp node's value is equal to given key
    if either of the above conditions is true
    come out of loop
    return temp node
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        TreeNode *temp = root;
        
        while(temp && temp->val != val)    
        {
            if(val > temp->val)
                temp = temp->right;
            else
                temp = temp->left;
        }
        return temp;
    }
};