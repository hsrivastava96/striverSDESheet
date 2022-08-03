/* 
Here,
We use Kahn's Algorithm of traversal in which we perform BFS traversal based on indegree of each node not visit value

Everything remains same except the data structure for pushing on to the queue
So, basically we push once the indegree of any neighbor becomes 0

We first check all the indegrees
then we push all the nodes with indegree = 0
then we perform BFS 
traversal by popping out from queue until it is empty and decrementing indegree of all neighbors of that node
while decrementing we simultaneously check if indegree is becoming 0
if so then we push on to the queue

*/

#include<queue>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    
    vector<int> adj[v+1], ans;
    vector<int> indegree(v+1, 0);

//     Create adjacency list and populate indegree vector
    for(auto edge:edges)
    {
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]] = indegree[edge[1]] + 1;
    }
    
//     Now, push all 0 indegree vertices in queue
    queue<int> q;
    for(int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
    
//     Now, run BFS
    while(!q.empty())
    {
        int currNode = q.front();
        q.pop();
        ans.push_back(currNode);
        
        for(auto neighbor:adj[currNode])
        {
            indegree[neighbor] = indegree[neighbor] - 1;
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    
    return ans;
    
    
}