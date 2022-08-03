/*
	Algo:

	Set src node dist to itself as 0
	push {0, 0} to min heap (I am starting from 0th node, you can start from anywhere)
	run while loop until q is empty, if empty go to step 10
	pop top from q (this will give us the minimum distance from all the existing edges)
	check if this node has been visited or not
	if not visited:

	Traverse through all the non visited neighbors of current node and push them along with their weights to q
	set visit for current node as visited in our vis ds
	add current node's weight to our sum
	go to step 3
	return sum

	TC: O(NLogN) (# of vertices * logN for priority queue)

	SC: O(N) 


*/

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // first prepare our adjacency list
        vector<bool> vis(V+1, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        q.push({0, 0});
        
        int sum = 0;
        while(!q.empty())
        {
            auto topPair = q.top();
            int currentNode = topPair.second;
            int currentWt = topPair.first;
            q.pop();
            
            if(!vis[currentNode])
            {
                for(auto neighbor:adj[currentNode])
                {
                    if(!vis[neighbor[0]])
                        q.push({neighbor[1], neighbor[0]});
                }
                vis[currentNode] = true;
                sum+=currentWt;
            }
        }
        return sum;
    }
};
