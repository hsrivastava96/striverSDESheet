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
    We are simply doing a level order traversal of our binary tree
    and keeping track of the current level while traversing each node at any level
    if the level is even then we are storing the node values of that level from 0th to last index 
    (i.e. size of queue for that level)
    otherwise we are storing the node values of that level from last index (i.e. size of queue for that level)
    to 0th index
    and at the end we are incrementing the level to move to the next level
    and pushing the temporary vector into our vector matrix, i.e. ans
    then we are returning ans 

 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        int level = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            vector<int> tempDS(size, 0);
            if(level % 2 == 0)
            {
                for(int i = 0; i < size; i++)
                {
                    TreeNode *tempNode = q.front();
                    q.pop();
                    tempDS[i] = tempNode->val;
                    
                    if(tempNode->left)
                        q.push(tempNode->left);
                    if(tempNode->right)
                        q.push(tempNode->right);
                }
            }
            else
            {
                for(int i = size-1; i >= 0; i--)
                {
                    TreeNode *tempNode = q.front();
                    q.pop();
                    tempDS[i] = tempNode->val;

                    if(tempNode->left)
                        q.push(tempNode->left);
                    if(tempNode->right)
                        q.push(tempNode->right);
                }
            }
            ans.push_back(tempDS);
            level++;
        }
        return ans;
    }
};