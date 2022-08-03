/*
    Algo:
    1: prepare adjacency list
    2: traverse all components by running a loop from i = 1 to i = n
    3: while traversing run bfs for all components
    4:in bfs 
    5: push start node in queue with parent as -1
    6: while q is not empty
         keep on popping front element from queue
    7: set current node as first and parent of this node as second from iterator
        because we know it is an undirected graph and here every edge represents edge from one node to other and vice versa
    8:  if while visiting neighbours (from adjacency list of any particular vertex) any neighbour was already visited
    then there is a possibility of cycle
    9: check if the visited node is equal to the parent or not if it is parent then it's not a cycle
    otherwise it is a cycle 
*/

#include<queue>
bool checkCycleBFS(int currNode, vector<bool> &vis, vector<int> adj[])
{
    queue<pair<int, int>> q;
    vis[currNode] = true;
    q.push({currNode, -1});
    
    while(!q.empty())
    {
        auto topPair = q.front();
        q.pop();
        int par = topPair.second;
        int currNode = topPair.first;
        for(auto it:adj[currNode])
        {
            if(!vis[it])
            {
                vis[it] = true;
                q.push({it, currNode});
            }
            else if(it != par)
                return true;
        }
    }
    return false;
}

bool checkCycleDFS(int currNode, int par, vector<bool> &vis, vector<int> adj[])
{
    vis[currNode] = true;
    
    for(auto it:adj[currNode])
    {
        if(!vis[it])
        {
            if(checkCycleDFS(it, currNode, vis, adj))
                return true;
        }
        else if(it != par)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> ds, adj[n+1];
    vector<bool> vis(n+1, false);
    
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
//             if(checkCycleBFS(i, vis, adj))
//                 return "Yes";
            if(checkCycleDFS(i, -1, vis, adj))
                return "Yes";
        }
    }
    return "No";
}
