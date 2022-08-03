/*
	Here, 
	everything is same as that of shortest distance algorithm for undirected graph

	There we used queue data structure
	Here, we use priority_queue
	Min heap to be specific
*/ 

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V+1, INT_MAX);
        
        // set the src node distance from itself to 0
        dist[S] = 0;
        
        // declare a priority queue (min heap)
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        // push current src node in q
        q.push({0, S});
        
        while(!q.empty())
        {
            auto topPair = q.top();
            q.pop();
            int currDist = topPair.first;
            int currNode = topPair.second;
            
            for(auto neighbor:adj[currNode])
            {
                int neighborWt = neighbor[1];
                int neighborNode = neighbor[0];
                int totalDist = currDist + neighborWt;
                
                if(totalDist < dist[neighborNode])
                {
                    dist[neighborNode] = totalDist;
                    q.push({totalDist, neighborNode});
                }
            }
        }
        return dist;
    }
};
