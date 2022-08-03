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
 */
class Solution {
public:
    TreeNode *bst(vector<int>& nums, int start, int end)
    {
        if(start > end)
           return NULL;
        
        TreeNode *newNode = new TreeNode();
        int mid = (start+end)/2;
        newNode->val = nums[mid];
        
        newNode->left = bst(nums, start, mid-1);
        newNode->right = bst(nums, mid+1, end);
        
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode *root = bst(nums, 0, nums.size()-1);
        return root;
    }
};