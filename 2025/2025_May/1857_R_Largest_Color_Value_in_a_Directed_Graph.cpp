// 2025 May 26
class Solution {
public:

    int dfs(int node, string& colors, vector<vector<int>>& adj, vector<vector<int>>& cnt, vector<int>& visited)
    {
        if (!visited[node])
        {
            visited[node] = 1;
            for (int next : adj[node])  // for each adjacent nodes for this node
            {
                if (dfs(next, colors, adj, cnt, visited) == INT_MAX) return INT_MAX;
                for (int c = 0; c < 26; c++)    // for each color, look for any updates for color counts
                {
                    cnt[node][c] = max(cnt[node][c], cnt[next][c]);
                }
            }
            cnt[node][colors[node] - 'a']++;    
            visited[node] = 2;
        }
        return visited[node] == 2 ? cnt[node][colors[node] - 'a'] : INT_MAX;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n = colors.size();
        vector<vector<int>> adj(n);                     // keep track of adjacent nodes
        vector<vector<int>> cnt(n, vector<int>(26));    // keep track of counts for each colors
        vector<int> visited(n);                         // keep track of visited nodes (unvisited, visiting, visited)

        for(auto& edge : edges)                         // form adj vector
        {
            adj[edge[0]].push_back(edge[1]);
        }

        int ans = 0;
        for (int i = 0; i < n && ans != INT_MAX; i++)   // if ans is INT_MAX, there is a cycle
        {
            ans = max(ans, dfs(i, colors, adj, cnt, visited));  // dfs to visit nodes and target for specific color
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
/*
solution reference
https://leetcode.com/problems/largest-color-value-in-a-directed-graph/solutions/6781399/using-dfs-c-python-java
*/
