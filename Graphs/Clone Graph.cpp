/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

    Algo:

    We have run DFS traversal on the graph
    While running DFS:
    we have created the clone for current node and have declared a vector to store it's neighbours

    Now, for each neighbour of current node we are checking if that has been visited or not
    because if it is visited then only we can get the address of the corresponding clone of that node

    so if it's visited, we directly store it in our neighbours vector like vis[it]

    otherwise we recursively call dfs() for that node (it) and send the state of our map (visited map)

    uptimately once the traversing of neighbours of current node gets over
    we store the neighbours to our clone and return the clone
*/


class Solution {
public:
    
    Node *dfs(Node *currNode, unordered_map<Node *, Node *> &vis)
    {
        vector<Node *> neighbours;
        Node *clone = new Node(currNode->val);
        vis[currNode] = clone;
        
        for(auto it:currNode->neighbors)
        {
            if(vis.find(it) != vis.end())
                neighbours.push_back(vis[it]);
            else
                neighbours.push_back(dfs(it, vis));
        }
        clone->neighbors = neighbours;
        return clone;
    }
    
    Node * bfs(Node *currNode)
    {
        queue<Node *> q;
        unordered_map<Node*, Node*> um;
        
        q.push(currNode);
        
        //create clone's first element
        Node *clone = new Node();
        clone->val = currNode->val;
        // clone->neighbors = NULL;
        
        // Push first element in map
        um[currNode] = clone;
        
        while(!q.empty())
        {
            Node *tempNode = q.front();
            q.pop();
            
            Node *currParent = um[tempNode];
            vector<Node*>  neighbors;
            for(auto neighbor: tempNode->neighbors)
            {
                Node *cloneNeighbor;
                if(um.find(neighbor) == um.end())
                {
                    cloneNeighbor = new Node();
                    cloneNeighbor->val = neighbor->val;
                    um[neighbor] = cloneNeighbor;
                    q.push(neighbor);
                }
                else
                    cloneNeighbor = um[neighbor];
                neighbors.push_back(cloneNeighbor);
            }
            currParent->neighbors = neighbors;
        }
        return clone;
    }
    
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node *, Node *> vis;
        
        if(!node)
            return NULL;
        
        if(node->neighbors.size() == 0)
        {
            Node *clone = new Node(node->val);
            return clone;
        }
        // return dfs(node, vis);
        return bfs(node);
        
    }
};