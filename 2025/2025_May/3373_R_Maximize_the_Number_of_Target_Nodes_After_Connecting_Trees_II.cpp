// 2025 May 29

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

    // dfs for a node to reach to target parent and each time the cnt (isEven) is alternates 0 and 1 
    int dfs(int i, int parent, bool isEven, const vector<vector<int>>& adj, bitset<100001>& even)
    {
        int cnt = isEven;
        even[i] = isEven;   // records if it is even in the bitset

        for (int j : adj[i])
        {
            if (j == parent) continue;
            cnt += dfs(j, i, !isEven, adj, even);
        }
        return cnt;
    }

    int dfs0(int i, int parent, bool isEven, const vector<vector<int>>& adj) 
    {
        int cnt = isEven;
        for (int j : adj[i])
        {
            if (j == parent) continue;
            cnt += dfs0(j, i, !isEven, adj);
        }
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        n = edges1.size() + 1;  // number of nodes in edges1 
        m = edges2.size() + 1;  // number of nodes in edges2

        vector<vector<int>> adj1(n);    // adjacency list for edges 1
        vector<vector<int>> adj2(m);    // adjacency list for edges 2

        bitset<100001> even1 = 0;

        build_adj(edges1, adj1);
        build_adj(edges2, adj2);

        int y = dfs0(0, -1, 1, adj2);
        int x = dfs(0, -1, 1, adj1, even1);

        vector<int> ans(n);
        int cnt = max(y, m - y);

        for (int i = 0; i < n; i++) // for each node, find its max possible number of nodes that are target to it when connecting a node from edge1 to edge2
        {
            if (even1[i]) ans[i] = x + cnt;
            else ans[i] = (n - x) + cnt;
        }

        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/solutions/6791084/dfs-bfs-with-parity-bitset-beats-100
*/
