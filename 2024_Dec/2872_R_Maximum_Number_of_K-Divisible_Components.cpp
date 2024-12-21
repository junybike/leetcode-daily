// 2024 Dec 21

class Solution {
public:

    int ans = 0;                // To record the maximum divisible components
    vector<vector<int>> adj;    // Adj 2d vector. For each node, it stores the adjacent nodes. 
    bitset<3001> visited = 0;   // To record if a certain node is visited 

    // To initialize the 'adj' 2d vector
    void init_adj(vector<vector<int>>& edges)
    {
        for (auto& e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }

    // DFS to find the maximum number of divisible components
    long long dfs(int i, vector<int>& values, int k)
    {
        visited[i] = 1;             // Set the current visiting node to bit 1 in 'visited'.
        long long sum = values[i];  // To record the sum of values that the adjacent nodes hold 

        // For each adjacent nodes, add their values together and set 'sum' to the remainder when divided by k.
        for (int j : adj[i])
        {
            if (visited[j]) continue;
            sum += dfs(j, values, k);
            sum %= k;
        }

        // If the 'sum' is divisible by k, increment 'ans'. It is divisible. 
        if (sum % k == 0) 
        {
            ans++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        adj.resize(n);              // Setting the size of 'adj' 2d vector
        init_adj(n, edges, values); // Initialize the 'adj' 2d vector
        dfs(0, values, k);          // DFS to find the maximum divisible components

        return ans;    
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-number-of-k-divisible-components/solutions/6169134/dfs-finds-components-79-ms-beats-98-73
*/
