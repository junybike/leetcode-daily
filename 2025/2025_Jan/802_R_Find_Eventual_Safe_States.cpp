// 2025 Jan 24

class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visit, vector<bool>& inStack)
    {
        if (inStack[node]) return true; // If true, this node is already in the stack (means a cycle)
        if (visit[node]) return false;  // If true, this node is already visited 

        visit[node] = true;     // Mark this node as visited
        inStack[node] = true;   // Mark this node as processing

        // Check all connected nodes from this node
        for (auto& adj : graph[node])
        {
            if (dfs(adj, graph, visit, inStack)) return true;
        }

        inStack[node] = false;  // Mark this node as processed
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();       // Number of nodes
        vector<bool> visit(n);      // Record nodes that are visited
        vector<bool> inStack(n);    // Record nodes that are currently processed in DFS

        // Iterating all nodes and its connected nodes in graph
        for (int i = 0; i < n; i++)
        {
            dfs(i, graph, visit, inStack);
        }

        // If the node is successfully processed, (not marked as false in 'inStack')
        // the node is a safe node.
        vector<int> safe;
        for (int i = 0; i < n; i++)
        {
            if (!inStack[i])
            {
                safe.push_back(i);
            }
        }

        return safe;
    }
};

/*
solution reference
https://leetcode.com/problems/find-eventual-safe-states/editorial

*/
