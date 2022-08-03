/*
    Simply run post order traversal
    and instead of printing root node swaproot->left with root->right
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) 
    {
        // code here
        if(!node)
            return;

        mirror(node->left);
        mirror(node->right);
        
        Node *temp;
        temp = node->right;
        node->right = node->left;
        node->left = temp;
    }
};