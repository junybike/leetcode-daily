// 2025 May 28

class Solution {
public:

    int n;
    int m;

    // forming adjacency list
    inline void build_adj(const vector<vector<int>>& edges, vector<vector<int>>& adj)
    {
        for (const auto& e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }

    // dfs for a node to reach to target parent and its cost to reach 
    int dfs(int i, int parent, int maxLen, const vector<vector<int>>& adj)
    {
        if (maxLen < 0) return 0;
        int cnt = 1;

        for (int j : adj[i])
        {
            if (j == parent) continue;
            cnt += dfs(j, i, maxLen - 1, adj);
        }
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) 
    {
        n = edges1.size() + 1;  // number of nodes in edges1 
        m = edges2.size() + 1;  // number of nodes in edges2

        vector<vector<int>> adj1(n);    // adjacency list for edges 1
        vector<vector<int>> adj2(m);    // adjacency list for edges 2

        build_adj(edges1, adj1);
        build_adj(edges2, adj2);

        int cnt = 0;
        for (int i = 0; i < m; i++) // find the max possible number of nodes target to node i from edges2
        {
            cnt = max(cnt, dfs(i, -1, k - 1, adj2));
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) // find each number of nodes target to node i from edges1 + cnt 
        {
            ans[i] = dfs(i, -1, k, adj1) + cnt;
        }

        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/solutions/6788180/dfs-x2-c-91-ms-beats-100-00
*/
