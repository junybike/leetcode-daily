// 2025 Mar 20

class Solution {
public:

    vector<int> parent; // to record each node's parent
    vector<int> depth;  // to record how far the node is from the parent

    int find(int node)
    {
        if (parent[node] == -1) return node;            // this node is not a child node
        else return parent[node] = find(parent[node]);  // updates this node's parent if this node is a child
    }

    void Union(int n1, int n2)      // to merge two nodes
    {
        int r1 = find(n1);
        int r2 = find(n2);
        
        if (r1 == r2) return;                       // two nodes already connected
        if (depth[r1] < depth[r2]) swap(r1, r2);    

        parent[r2] = r1;                            // makes the deeper node parent of the other node
        if (depth[r1] == depth[r2]) depth[r1]++;    // case where two nodes have the same depth. increase depth of a node
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {   
        parent.resize(n, -1);       
        depth.resize(n, 0);

        vector<int> cost(n, -1);    // each node's cost
        vector<int> ans;            // to store costs for each query

        for (auto& e : edges)       // to connect edges that can be connected
        {
            Union(e[0], e[1]);
        }
        for (auto& e : edges)       // compute the costs: bitwise AND of all edges' cost
        {
            int root = find(e[0]);
            cost[root] &= e[2];
        }
        for (auto& q : query)
        {
            int s = q[0];
            int e = q[1];

            if (find(s) != find(e)) ans.push_back(-1);  // case where the nodes cannot be reached
            else                                        
            {
                int root = find(s);
                ans.push_back(cost[root]);
            }
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/editorial
*/
