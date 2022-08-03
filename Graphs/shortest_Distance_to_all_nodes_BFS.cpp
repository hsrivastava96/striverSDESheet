class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<int> dist(n+1, INT_MAX);

//         push 0th index in queue
        queue<int> q;
        q.push(0);
        
// Set 0th index distance from 0th index to 0
        dist[0] = 0;
//         Traverse via BFS
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            int currentDistFromZero = dist[node];
            
            for(auto neighbor:graph[node])
            {
                int tempDist = currentDistZero + 1;
                if(tempDist < dist[neighbor])
                {
                    dist[neighbor] = tempDist;
                    q.push(neighbor);
                }
            }
        }
    }
};