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

/*
[3,2,1,6,0,5]

l -> [3,2,1] 
    => l -> [] -> return because no elements in array
    => r -> [2, 1] 
        => l -> [] -> return because no elements in array
        => r -> [1] 
            l -> [] -> return because no elements in array
            r -> [] -> return because no elements in array
            
    
r -> [0, 5]
    => l -> [0]
        => l -> [] -> return because no elements in array
        => r -> [] -> return because no elements in array
    => r -> [] -> return because no elements in array
    
    
Algo:
    boundary cond: if l > r return
    maxElemInd in range (l, r)
    create newNode 
    set newNode->val to maxELem
    newNode->left = fun(l, maxElemInd - 1, vector)
    newNode->right = fun(maxElemInd + 1, r, vector)
    return newNode;
*/

class Solution {
public:
    
    TreeNode * maxBinTree(int l, int r, vector<int> &nums)
    {
        if(l > r)
            return NULL;

        int maxElem = INT_MIN, maxElemInd = -1;
        for(int i = l; i <= r; i++)
        {
            if(nums[i] > maxElem)
            {
                maxElem = nums[i];
                maxElemInd = i;
            }
        }
        
        TreeNode *newNode = new TreeNode();
        newNode->val = maxElem;
        newNode->left = maxBinTree(l, maxElemInd-1, nums);
        newNode->right = maxBinTree(maxElemInd+1, r, nums);
        
        return newNode;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return maxBinTree(0, nums.size()-1, nums);
    }
};

