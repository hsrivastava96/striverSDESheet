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
    Using Level Order Traversal with NULL to increment level once NULL is found in queue
    Then simply return level
 */


class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        
        queue<TreeNode *> q;
        
        q.push(root);
        q.push(NULL);
        
        int level = 0;
        while(!q.empty())
        {
            TreeNode *tempNode = q.front();
            q.pop();
            
            if(tempNode == NULL)
            {
                level++;
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                if(tempNode->left)
                    q.push(tempNode->left);
                if(tempNode->right)
                    q.push(tempNode->right);
            }
            
        }
        return level;
    }
};