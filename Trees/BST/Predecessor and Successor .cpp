void inorder(Node *root, vector<Node *> &ds)
{
    if(!root)
        return;
    
    inorder(root->left, ds);
    ds.push_back(root);
    inorder(root->right, ds);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    vector<Node *> ds;

    if(!root)
        return;
    inorder(root, ds);
    
    int n = ds.size();
    
    int i = n-1, j = 0, lFlag = 0, rFlag = 0;
    while(i >= 0 && lFlag == 0)
    {
        if(ds[i]->key < key)
            lFlag = 1;
        i--;
    }
    
    while(j < n && rFlag == 0)
    {
        if(ds[j]->key > key)
            rFlag = 1;
        j++;
    }
    
    if(lFlag == 1)
        pre = ds[i+1];
    else
        pre = NULL;
    
    if(rFlag == 1)
        suc = ds[j-1];
    else
        suc = NULL;

// Your code goes here

}