/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

    Algo:
    
    Run level order traversal and set temp and prev as fisrt node in queue 
    run a loop from 2nd to last node in queue
    in each loop set next of prev to current node
    after loop ends set last node's next to NULL

    after q is empty return root

*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return NULL;
        
        queue<Node *> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            Node *temp = q.front();
            Node *prev = q.front();
            q.pop();

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);

            for(int i = 1; i < size; i++)
            {
                temp = q.front();
                prev->next = temp;
                prev = temp;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
            }
            temp->next = NULL;
        }
        return root;
    }
};