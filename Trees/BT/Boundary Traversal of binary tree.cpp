// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

/*
    Algo:
    Logic here is to find left boundary except leaves
    Then find Leaves except root if root is a leaf then return root's value as vector
    Then find right boundary in reverse order

    put them all in a vector and return
*/


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
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:
    
    bool isLeaf(Node *root)
    {
        if(root->left == NULL && root->right == NULL)
            return true;
        return false;
    }
    
    void leaves(Node *root, vector<int> &ans)
    {
        if(isLeaf(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left)
            leaves(root->left, ans);
        if(root->right)
            leaves(root->right, ans);
    }

    void leftBoundary(Node *root, vector<int> &ans)
    {
        Node *temp = root->left;   
        while(temp)
        {
            if(!isLeaf(temp))
                ans.push_back(temp->data);
            if(temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    
    void rightBoundary(Node *root, vector<int> &ans)
    {
        Node *temp = root->right;
        vector<int> tempDS;
        
        while(temp)
        {
            if(!isLeaf(temp))
                tempDS.push_back(temp->data);
            if(temp->right)
                temp = temp->right;
            else
                temp = temp->left;
        }
        
        int size = tempDS.size();
        
        for(int i = size-1; i >= 0; i--)
            ans.push_back(tempDS[i]);
    }


    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root)
            return ans;
        
        ans.push_back(root->data);
        
        if(isLeaf(root))
            return ans;

        leftBoundary(root, ans);
        leaves(root, ans);
        rightBoundary(root, ans);
        
        return ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

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
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends