/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

    Algo:
    Check if current node is either of the two nodes or not
    if yes then this node is our temporary answer for the following cases:
        => the other node could be in either of the subtrees of this node
    Search in leftSubtree and rightSubTree
        => In this case there could be 3 scenarios
            We find one node in leftSubTree and one node in rightSubTree
            => both will not be NULL then in this answer will be parent node of subtrees, i.e. current root node
            either of the subTrees will be NULL, 
            => in this case return not NULL one and keep hecking until both the sub trees are not null
            and return that root 
 */
class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode *l = lowestCommonAncestor(root->left, p, q);
        TreeNode *r = lowestCommonAncestor(root->right, p, q);
        
        if(l != NULL && r != NULL)
            return root;
        else
        {
            if(l)
                return l;
            return r;
        }
    }
};