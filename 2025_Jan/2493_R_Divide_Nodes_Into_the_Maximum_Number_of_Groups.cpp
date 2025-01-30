class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjList(n); // record adjacent nodes for each node in 'edges'
        for (auto& e: edges)
        {
            adjList[e[0] - 1].push_back(e[1] - 1);
            adjList[e[1] - 1].push_back(e[0] - 1);
        }    

        vector<int> colors(n, -1);  // color each nodes. each adjacent nodes must have different colors
        for (int i = 0; i < n; i++)
        {
            if (colors[i] != -1) continue;  
            colors[i] = 0;

            // If adjacent nodes have same colors, this case not possible.
            if (!isBipartite(adjList, i, colors)) return -1;
        }

        vector<int> dist(n);    // stores longest shortest path between any pairs of node for each node
        for (int i = 0; i < n; i++)
        {
            dist[i] = getPathLength(adjList, i, n);
        }

        int maxGroups = 0;      // Stores the max number of groups across all components
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;
            maxGroups += getNumberOfGroups(adjList, i, dist, visited);
        }

        return maxGroups;
    }

private:

    bool isBipartite(vector<vector<int>>& adjList, int node, vector<int>& colors)
    {
        for (int adj : adjList[node])
        {
            if (colors[adj] == colors[node]) return false;  // Adjacent node has the same color as the current node
            if (colors[adj] != -1) continue;                
            
            colors[adj] = (colors[node] + 1) % 2;                   // assigning the opposite color of the current node
            if (!isBipartite(adjList, adj, colors)) return false;   // checks the adjacent's node's adjacent nodes' color
        }
        return true;
    }

    int getPathLength(vector<vector<int>>& adjList, int src, int n)
    {
        queue<int> q;                   // to store the nodes to be processed
        vector<bool> visited(n, false); // to keep track of visited nodes

        q.push(src);            // initially, src node is pushed to 'q'
        visited[src] = true;    // src node is visited
        int dist = 0;

        while (!q.empty())
        {
            // to process all nodes in 'q'
            int nodeInLayer = q.size();
            for (int i = 0; i < nodeInLayer; i++)
            {
                int cur = q.front();
                q.pop();

                // Visiting all adjacent nodes of the 'cur'
                for (int adj : adjList[cur])
                {
                    if (visited[adj]) continue;
                    visited[adj] = true;
                    q.push(adj);
                }
            }
            // After each layer, add distance
            dist++;
        }
        return dist;
    }

    int getNumberOfGroups(vector<vector<int>>& adjList, int node, vector<int>& dist, vector<bool> &visited)
    {
        int maxGroups = dist[node];
        visited[node] = true;

        // Computing the 'maxGroup' for all unvisited adjacent nodes
        for (int adj : adjList[node])
        {
            if (visited[adj]) continue;
            maxGroups = max(maxGroups, getNumberOfGroups(adjList, adj, dist, visited));
        }
        return maxGroups;
    }
};
/*
solution reference
https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/editorial
*/
