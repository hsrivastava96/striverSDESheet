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
    Basically divide the problem into sub problems:

    if root == NULL => return 0 because no height is there

    Now, if root is not NULL then it might have one of the following situations:
    1: It has both left and right child
        => In this case left and right both will return their respective heights, say l and r
    2: It has either right or left child:
        => In this case either left or right will return 0
        => so consider l, r
    3: It has no child
        => In this case it's l and r == 0
        So, just return 1 from this node as it is contributing to the height of it's parent as one node

    at each level if root is not null
    check if (l+r) > max
    if Yes then update max = l+r
 */
class Solution {
public:
    
    int findMaxPath(TreeNode *root, int &max)
    {
        if(!root)
            return 0;
        
        int l = findMaxPath(root->left, max);
        int r = findMaxPath(root->right, max);
        
        if(l+r > max)
            max = l+r;
        
        if(l == 0 && r == 0)
            return 1;
        else
        {
            if(l > r)
                return l + 1;
            return r + 1;
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        int max = 0;
        findMaxPath(root, max);
        return max;
    }
};