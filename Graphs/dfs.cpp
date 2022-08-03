/*
    DFS Algo:
    Step 1: Visit the currentNode
    Step 2: Get non visited neighbor and send it to Step 1, if no non-visited neighbor is there then return

*/

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int currentNode, vector<int> &vis, vector<int> adj[], vector<int> &ds)
    {
        ds.push_back(currentNode);
        vis[currentNode] = 1;
        
        for(auto it:adj[currentNode])
        {
            if(vis[it] == 0)
                dfs(it, vis, adj, ds);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int> vis(V+1, 0);
        vector<int> ds;
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
                dfs(i, vis, adj, ds);
        }
        return ds;
    }
};