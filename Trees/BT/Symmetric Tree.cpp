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
    for each level order traversal put all node's value including null ones (for null put INT_MIN in ds) in a vector
    after every loop check if vector is palindrome or not
    if not then return false
    otherwise after complete traversal return true
 */
class Solution {
public:
    bool checkPalindrome(vector<int> ds)
    {
        int n = ds.size();
        
        for(int i = 0, j = n-1; i <=j; i++, j--)
        {
            if(ds[i] != ds[j])
                return false;
        }
        return true;
    }
    
    // void printDs(vector<int> ds)
    // {
    //     for(auto it:ds)
    //         cout<<it<<" ";
    //     cout<<endl;
    // }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return false;
        
        queue<TreeNode *> q;
        
        q.push(root);
        
        int level = 1;
        while(!q.empty())
        {
            vector<int> ds;
            int size = q.size();
            // cout<<"Level: "<<level<<endl;
            for(int i = 0; i < size; i++)
            {
                TreeNode *tempNode = q.front();
                q.pop();                
                
                if(tempNode != NULL)
                {
                    ds.push_back(tempNode->val);
                    q.push(tempNode->left);
                    q.push(tempNode->right);
                }
                else
                    ds.push_back(INT_MIN);
            }
            bool check = checkPalindrome(ds);
            // printDs(ds);
            if(!check)
                return false;
        }
        return true;
    }
};