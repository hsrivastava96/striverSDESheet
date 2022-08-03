/*
    BFS Algo:
    Step 1: Visit and push currentNode on to the queue
    Step 2: Check if queue is empty or not, if not empty move to step 3 otherwise go to step 5
    Step 3: Pop queue, store poppedNode's data in bfs o/p ds
    Step 4: visit and push all non visited neighbors of poppedNode into the queue and go to step 2
    Step 5: Print bfs ds

*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        // Code here
        vector<int> vis(V+1, 0), ds;
        

        queue<int> q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            int currNode = q.front();
            q.pop();
            ds.push_back(currNode);
            for(auto it:adj[currNode])
            {
                if(vis[it] == 0)
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return ds;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends