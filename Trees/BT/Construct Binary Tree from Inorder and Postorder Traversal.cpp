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
    e.g.
    inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    reverse of postorder: [3, 20, 7, 15, 9]
    
    Here, if we see in revPost every node is root of any right sub tree 
    and if nothing is present then it is moving to left sub tree
    
    So, basically first right subtree is getting built and current node's right child is getting added
    followed by left child

    So, considering this we have applied the same concept from preorder and inorder here as well
    with revPost as preorder vector 

    with slight changes with respect to the index ranges for respective vectors
 */
class Solution {
public:
    
    TreeNode *getTree(vector<int> &postorder, int pl, int pr, vector<int> &inorder, int il, int ir, unordered_map<int, int> &m)
    {
        if(pl > pr || il > ir)
            return NULL;
        
        TreeNode *newNode = new TreeNode();
        newNode->val = postorder[pl];
        
        int nodeInd = m[postorder[pl]];
        int numsRight = ir - nodeInd;
        
        newNode->right = getTree(postorder, pl+1, pl + numsRight, inorder, nodeInd + 1, ir, m);
        newNode->left = getTree(postorder, pl + numsRight + 1, pr, inorder, il, nodeInd - 1, m);
        
        return newNode;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        unordered_map<int, int> m;
        vector<int> revPost;
        
        for(int i = 0, j = postorder.size() - 1; i < inorder.size(); i++, j--)
        {
            m[inorder[i]] = i;
            revPost.push_back(postorder[j]);
        }
        
        TreeNode *root = getTree(revPost, 0, revPost.size() - 1, inorder, 0, inorder.size() - 1, m);
        return root;
    }
};