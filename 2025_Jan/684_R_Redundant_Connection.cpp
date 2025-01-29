// 2025 Jan 29

class Solution {
private:

    bool dfs(int src, int target, vector<bool>& visited, vector<int> adjList[]) 
    {
        visited[src] = true;                // Mark this node as visited
        if (src == target) return true;     // If src and target are identical, return true.

        int isFound = false;            // Indicates if there is a path between 'src' and 'target'
        for (int adj : adjList[src])    // For each adj nodes for 'src', determine if it leads to the 'target'
        {
            if (!visited[adj]) 
            {
                isFound = isFound || dfs(adj, target, visited, adjList);
            }
        }
        return isFound; 
    }

public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int N = edges.size();   // number of nodes in 'edges'
        vector<int> adjList[N]; // records all adjacent nodes for each node in 'edges'

        for (auto& e : edges) 
        {
            vector<bool> visited(N, false); // keep track of visited nodes

            if (dfs(e[0] - 1, e[1] - 1, visited, adjList)) return e;

            // maintaining the adjList
            adjList[e[0] - 1].push_back(e[1] - 1);
            adjList[e[1] - 1].push_back(e[0] - 1);
        }

        return {};
    }
};

/*
solution reference
https://leetcode.com/problems/redundant-connection/submissions/1523979692
*/
