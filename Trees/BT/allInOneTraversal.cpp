/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void getTraversal(BinaryTreeNode<int> *root, vector <int> &pre, vector <int> &in , vector <int> &post)
{
    if(!root)
        return;
    
    pre.push_back(root->data);
    getTraversal(root->left, pre, in, post);
    in.push_back(root->data);
    getTraversal(root->right, pre, in, post);
    post.push_back(root->data);
}


vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<vector<int>> ds;
    vector <int> pre, in , post;
    getTraversal(root, pre, in , post);

    ds.push_back(in);
    ds.push_back(pre);
    ds.push_back(post);
    return ds;
}