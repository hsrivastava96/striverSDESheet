/*
    Algo:
    Simply traverse the graph using BFS algo
    
    BFS Algo:
    Step 1: Visit and push currentNode on to the queue
    Step 2: Check if queue is empty or not, if not empty move to step 3 otherwise go to step 5
    Step 3: Pop queue, store poppedNode's data in bfs o/p ds
    Step 4: visit and push all non visited neighbors of poppedNode into the queue and go to step 2
    Step 5: Print bfs ds

    In this, instead of visit let us have color ds to track the color of any node
    now if for any neighbor of poppedNode that was visited earlier if the color is same as that of poppedNode
    then the graph is not bipartite

    If the above condition doesn't gets true at all, then we say it's a bipartite graph

    DFS Algo:
    Step 1: Visit the currentNode
    Step 2: Get non visited neighbor and send it to Step 1, if no non-visited neighbor is there then return
*/

class Solution {
public:
    bool bfs(int currNode, vector<int> color, vector<vector<int>> &adj)
    {
        queue<int> q;        
        q.push(currNode);
        color[currNode] = 0;

        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            int currColor = color[top];
            int changeColor = (currColor == 0)?1:0;
            for(auto neighbor:adj[top])
            {
                if(color[neighbor] == -1)
                {
                    q.push(neighbor);
                    color[neighbor] = changeColor;
                }
                else if(color[neighbor] != changeColor)
                    return false;
            }
        }
        return true;
    }
    
    bool dfs(int currNode, int parentColor, vector<int> &color, vector<vector<int>> &adj)
    {
        color[currNode] = (parentColor == -1 || parentColor == 1)?0:1;   
        for(auto neighbor:adj[currNode])
        {
            if(color[neighbor] == -1)
            {
                if(!dfs(neighbor, color[currNode], color, adj))
                    return false;
            }
            else if(color[neighbor] == color[currNode])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n = graph.size(), prevC = 0;
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                // if(!bfs(i, color, graph))
                //     return false;
                if(!dfs(i, -1, color, graph))
                    return false;
            }
        }
        return true;
    }
};