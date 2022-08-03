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

    E.G.:
    preorder = [3,9,20,15,7]
    inorder = [9,3,15,20,7]

    inOrderMap= {
        9:0,
        3:1,
        15:2,
        20:3,
        7:4
    }

    **** (VERY IMPORTANT) we need a map because we want to find out the index of any preorder element in inorder vector.
    
    Now, we basically make a recursive call that for every index in preorder traversal 
    what will be the left subtree and right sub tree (roots of which will become left and right child respectively for current node)

    and then we continue the process
 */
class Solution {
public:
    
    TreeNode *bT(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir, unordered_map<int, int> &m)
    {
        if(pl > pr || il > ir)
            return NULL;
        
        TreeNode *newNode = new TreeNode();
        newNode->val = preorder[pl];

        int nodeInd = m[preorder[pl]];    
        int numsPre = nodeInd - il;
        newNode->left = bT(preorder, inorder, pl+1, pl + numsPre, il, nodeInd-1, m);
        newNode->right = bT(preorder, inorder, pl + numsPre + 1, pr, nodeInd + 1, ir, m);
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> m;
        
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        
        TreeNode *root = bT(preorder, inorder, 0, preorder.size()-1, 0, inorder.size() - 1, m);
        return root;
    }
};