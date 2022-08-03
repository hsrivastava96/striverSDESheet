/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};


Algo:

The idea here is to again traverse using the line traversing concept
While traversing push every root to ques and while popping just check if the line key is present in map or not
If line key is not present then insert data to map using line as key

check if left node is present
If yes then push left child with line -1 as horizontal distance of node from root node

check if right node is present
If yes then push child with line + 1 as horizontal distance from root node

*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.


    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ds;
        
        queue<pair<Node *, int>> q;
        map<int, int> m;
        
        q.push({root, 0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int line = it.second;
            Node *tempNode = it.first;
            
            if(m.find(line) == m.end())
                m[line] = tempNode->data;
            
            if(tempNode->left)
                q.push({tempNode->left, line-1});
            if(tempNode->right)
                q.push({tempNode->right, line+1});
        }
        
        for(auto it:m)
            ds.push_back(it.second);
        return ds;
    }

};
