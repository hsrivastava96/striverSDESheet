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
        Store preorder in another vector
        Sort this vector
        This vector will become our inorder traversal vector
        Now, apply the logic of Binary Tree using inorder and post order traversal
 */
class Solution {
public:
    TreeNode *bst(vector<int> &preorder, int pStart, int pEnd, vector<int> &inorder, int iStart, int iEnd, unordered_map<int, int> &m)
    {
        if(pStart > pEnd || iStart > iEnd)
           return NULL;
        
        TreeNode *newNode = new TreeNode();
        newNode->val = preorder[pStart];
        
        int nodeInd = m[preorder[pStart]];
        int nodeLeft = nodeInd - iStart;
        
        newNode->left = bst(preorder, pStart+1, pStart + nodeLeft, inorder, iStart, nodeInd -1, m);
        newNode->right = bst(preorder, pStart + nodeLeft + 1, pEnd, inorder, nodeInd + 1, iEnd, m);
        
        return newNode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        vector<int> inorder;
        for(auto it:preorder)
            inorder.push_back(it);
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> m;
        
        for(int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;        
        
        TreeNode *root = bst(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() - 1, m);
        return root;
    }
};