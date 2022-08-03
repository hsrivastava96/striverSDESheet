

void dfs(int currNode, vector<bool> &vis, stack<int> &topoOrder, vector<pair<int, int>> adj[])
{
	vis[currNode] = true;

	for(auto neighbor:adj[currNode])
	{
		if(!vis[neighbor.first])
			dfs(neighbor.first, vis, topoOrder, adj);
	}

	topoOrder.push_back(currNode);
}

void getShortestPath(int V, vector<vector<int>> &edges)
{
	vector<pair<int, int>> adj[V+1];
	vector<int> dist(V+1, INT_MAX);
	vector<bool> vis(V+1, false);
	stack<int> topoOrder;

	// Prepare Adjacency List
	// Here, edge[0] is source, edge[1] is destination and edge[2] is weight of edge
	for(auto edge:edges)
		adj[edge[0]].push_back({edge[1], edge[2]});

	// Get topological stack using DFS
	for(int i = 0; i < V; i++)
	{
		if(!vis[i])
			dfs(i, vis, stack, adj);
	}

	// set 0th node distance from itself as 0
	dist[0] = 0;

	// Now traverse all neighbors for all nodes in stack and find the minimum distance for each
	while(!topoOrder.empty())
	{
		auto topPair = topoOrder.top();
		int topNode = topPair.first;
		int currDist = topPair.second;
		topoOrder.pop();

		if(currDist != INT_MAX)
		{
			for(auto neighbor:adj[topNode])
			{
				int currNode = neighbor.first;
				int currWeight = neighbor.second;

				int totalDist = currDist + currWeight;
				if(totalDist < dist[currNode])
					dist[currNode] = totalDist;
			}
		}
	}

	for(auto d:dist)
		cout<<d<<" ";
	cout<<endl;
}