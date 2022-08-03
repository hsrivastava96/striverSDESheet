/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

    Algo:
        It's LCA by considering properties of BST. 
        Here, p, q can be both smaller than or larger than current node
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
            return NULL;

        int currVal = root-val;
        int pVal = p->val;
        int qVal = q->val;

        if(currVal < pVal && currVal < qVal)
            return lowestCommonAncestor(root->right, p, q);
        if(currVal > pVal && currVal > qVal)
            return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};