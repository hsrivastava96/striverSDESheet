/*
    Algo:
                20
              /    \
            8       22
          /   \    /   \
         5      34      25
              /    \
            10      12

We basically follow a line traversal.
Here, we enque root and pop and insert current node with it's horizontal distance from root node
While popping we insert the node in a map using key as horizontal distance from root node
If there is no such key then new data will get inserted in map
If there is a key then the data gets overriden
The best thing about map is that data gets stored in sorted fashion based on the keys
so at the end we traverse the map and put data from map into our vector and return it 
*/



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) 
    {
        // Your Code Here
        

        vector<int> ds;
        
        if(!root)
            return ds;
            
        queue<pair<int, Node *>> q;
        map<int, int> m;
        
        q.push(pair<int, Node *>(0, root));
        
        int l = 0;
        while(!q.empty())
        {
            auto tempV = q.front();
            q.pop();
            Node *tempNode = tempV.second;
            int line = tempV.first;
            
            m[line] = tempNode->data;
            if(tempNode->left)
                q.push(pair<int, Node *>(line-1, tempNode->left));
            if(tempNode->right)
                q.push(pair<int, Node *>(line+1, tempNode->right));
        }
        
        for(auto it:m)
            ds.push_back(it.second);
        return ds;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}


  // } Driver Code Ends