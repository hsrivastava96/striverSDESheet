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

    Here, main thing is the use of map within a map and multiset within the inner map
    So basically outer map maps information w.r.t each line
    Inner map stores information w.r.t each level within each line
    and multiset stores the values in sorted order for same level values on the same line

    then we have simply traversed like bfs
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        map<int, map<int, multiset<int>>> m;
        queue<pair<TreeNode *, pair<int, int>>> q;
        
        vector<vector<int>> ans;
        if(!root)
            return ans;
        
        q.push({root, {0, 0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int line = it.second.first;
            int level = it.second.second;
            TreeNode *temp = it.first;
            
            m[line][level].insert(temp->val);            

            if(temp->left)
                q.push({temp->left, {line-1, level+1}});
            if(temp->right)
                q.push({temp->right, {line+1, level+1}});
        }
        
        for(auto it:m)
        {
            vector<int> tempVec;
            for(auto it2:it.second)
                tempVec.insert(tempVec.end(), it2.second.begin(), it2.second.end());
            ans.push_back(tempVec);
        }
        
        
        // for(auto it:m)
        //     cout<<it.second[0].second;
            // ans.push_back(it.second);
        
        return ans;
    }
};