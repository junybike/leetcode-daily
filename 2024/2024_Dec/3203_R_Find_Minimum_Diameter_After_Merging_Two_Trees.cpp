// 2024 Dec 24

template<typename T>
void updateMax(T& current, T candidate)
{
    current = max(current, candidate);
}

class Solution {
public:

    vector<int> adj[200005];    // To store the adjacent nodes
    int depth[200005];          // Keep track of all node's depth
    int farthestNodeA;          // The farthest node from some arbitrary node in a tree
    int farthestNodeB;          // The farthest node from the 'farthestNodeA'

    // DFS to find the farthest node in a tree.
    void dfs(int current, int parent, int& farthest)
    {
        depth[current] = depth[parent] + 1;
        
        if (farthest == -1 || depth[current] > depth[farthest]) farthest = current;
        for (int neighbor : adj[current])
        {
            if (neighbor != parent) dfs(neighbor, current, farthest);
        }
    }

    // Find the largest diameter in a tree.
    int get_diameter()
    {
        // Find a farthest node from some arbitrary node in a tree
        farthestNodeA = -1;
        dfs(1, 0, farthestNodeA);

        // Find a farthest node from the 'farthestNodeA'
        farthestNodeB = -1;
        dfs(farthestNodeA, 0, farthestNodeB);

        return depth[farthestNodeB] - 1;
    }

    // Finds the distance of root node to the farthest node in a tree (half of the diameter)
    // and the other half of the diameter  
    pair<int, int> process_tree(const vector<vector<int>>& edges)
    {
        int n = edges.size() + 1;

        // Set 'adj' vector
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }

        // Initialize the 'adj' vector
        for (auto& edge : edges)
        {
            int u = edge[0] + 1;
            int v = edge[1] + 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Returns half of diameter and the other half
        int diameter = get_diameter();
        return {diameter / 2, diameter - diameter / 2};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        pair<int, int> tree1 = process_tree(edges1);    // Finds the first tree's half diameter pair 
        pair<int, int> tree2 = process_tree(edges2);    // Finds the second tree's half diameter pair

        // The minimum diameter is the sum of largest half diameter of first and second tree and additional edge connecting the two tree (1).
        int ans = max(tree1.first + tree1.second, tree2.first + tree2.second);
        updateMax(ans, max(tree1.first, tree1.second) + max(tree2.first, tree2.second) + 1);

        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/solutions/6179417/100-beats-bfs-greey-easy-explation
*/
