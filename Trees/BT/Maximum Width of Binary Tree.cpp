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

    ALgo:
    To find the width, we need number of nodes that can come 
    in between the available left most node and right most node at any level

    Now, out of all the widths we basically need to find the maximum width

    To do so, we need to give the nodeId to each node starting from 0th node ending to 2^0 + 2^1 + ... 2^n
    Here, n is the maximum level of our binary tree

    So, for any node, it's left child's id = currNodeId * 2 + 1, right child's id = currNodeId * 2 + 2

                       A0
                    /      \
                  1B         C2
                  /   \   /      \
                D3    4E|F5      G6
              /  \   / \/\   /        \
            H7     I8|J9|L10 11K|12M|13N   14O

    So, 
    Now, at each level, we simply find the size of the queue, 
    Here, first node will be our leftMost available node and 
    last node will be our rightMost available node

    So, we simply width using (rightMost - leftMost + 1)
    then we compare it with our max width (initially max width = INT_MIN)

    At the end we will be left with max width of our tree

    return max
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode *, int>> q;
        
        if(!root)
            return 0;
        
        q.push({root, 0});
        
        long long int lVal = 0, rVal = 0, node_id = 0, max = INT_MIN;
        while(!q.empty())
        {
            int size = q.size();
            for(long long int i = 0; i < size; i++)
            {
                auto tempPair = q.front();
                TreeNode *tempNode = tempPair.first;
                long long int nodeVal = tempPair.second;
                q.pop();            
                
                if(i == 0)
                    lVal = nodeVal;
                if(i == size-1)
                    rVal = nodeVal;

                if(tempNode->left)
                    q.push({tempNode->left, nodeVal*2+1});
                if(tempNode->right)
                    q.push({tempNode->right, nodeVal*2+2});
            }
            if((rVal - lVal + 1) > max)
                max = (rVal - lVal + 1);
        }
        return (max);
    }
};