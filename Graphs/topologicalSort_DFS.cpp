/*
	Prerequisite: Graph should be a DAG (Directed Acyclic graph)
	
	Run DFS
	and after traversing each neighbor of any given node put the current node into the stack

	The stack will represent all the nodes in topological order 
	because if we think recursively w.r.t the graph in DFS context then all the v node from (u, v) pair 
	of topological order will come after the parent node

	So, use of stack will help us store v first then u
*/
class Solution
{
	public:
	//Function to return list containing vertices in Topological order.
	
	void dfs(int currNode, vector<int> adj[], vector<bool> &vis, stack<int> &topoOrder)
	{
	    vis[currNode] = true;
	    
	    for(auto neighbor:adj[currNode])
	    {
	        if(!vis[neighbor])
	            dfs(neighbor, adj, vis, topoOrder);
	    }
	    
	    topoOrder.push(currNode);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V+1, 0);
        vector<int> ans;
	    stack<int> topoOrder;
	    
	    for(int i = 0; i < V; i++)
	    {
	        if(!vis[i])
	            dfs(i, adj, vis, topoOrder);
	    }
	    
	    while(!topoOrder.empty())
	    {
	        ans.push_back(topoOrder.top());
	        topoOrder.pop();
	    }
	    return ans;
	}
};
