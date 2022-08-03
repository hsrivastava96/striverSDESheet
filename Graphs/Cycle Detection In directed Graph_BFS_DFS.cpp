/*
    DFS Algo:
    Step 1: Visit the currentNode
    Step 2: Get non visited neighbor and send it to Step 1, if no non-visited neighbor is there then return

    Here, we will bring in the concept of dfs visit, which means that for one complete dfs traversal
    we shall keep visit track in a ds and once the visits for a specific node and it's neighbors are finished
    we simply set the visit for the current node to 0 because
    what happens in case of directed graph is, if we  want to find a cycle
    then we might come across neighbor which might have already been visited earlier but that might have happened in 
    any previous sub dfs traversal so, for that case we are having this dfsVis ds to check for current dfs traversal

    BFS:
    We make use of Kahn's algo to check cycle
*/



bool dfs(int currNode, vector<bool> &vis, vector<bool> &dfsVis, vector<int> adj[])
{
    vis[currNode] = true;
    dfsVis[currNode] = true;
    
    for(auto neighbor: adj[currNode])
    {
        if(!vis[neighbor])
        {
            if(dfs(neighbor, vis, dfsVis, adj))
                return true;
        }
        else if(dfsVis[neighbor])
            return true;
    }
    dfsVis[currNode] = false;
    return false;
}

bool bfs(int numCourses, vector<int> &indegree, vector<int> adj[])
{
    queue<int> q;
    for(int i = 0; i < numCourses; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
    int count = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        
        for(auto neighbor:adj[node])
        {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
    if(count == numCourses)
        return true;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) 
{
  // Write your code here.
    vector<int> adj[n+1];
    vector<bool> vis(n+1, 0);
    vector<bool> dfsVis(n+1, 0);
    
    for(auto edge: edges)
    {
        adj[edge.first].push_back(edge.second);    
        indegree[edge.second]++;
    }
    
    // DFS
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i, vis, dfsVis, adj))
                return true;
        }
    }
    return false;

    // BFS
    bool res = bfs(n, indegree, adj);
    return res;
}