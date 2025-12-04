// 2025 Jan 18

class Solution {
public:

    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) 
    {
        int n = grid.size();        // Number of rows in grid
        int m = grid[0].size();     // Number of cols in grid

        // Min heap. Values: cost, row, col. Highest cost in front
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        // Record minimum cost to reach each cell
        vector<vector<int>> min_cost(n, vector<int>(m, INT_MAX));
        min_cost[0][0] = 0;

        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            
            int cost = cur[0];
            int row = cur[1];
            int col = cur[2];

            // Case where we've already found a better cost. 
            if (min_cost[row][col] != cost) continue;

            for (int i = 0; i < 4; i++)
            {
                // New possible location from the current location
                int new_row = row + dir[i][0];
                int new_col = col + dir[i][1];

                // Check if the new location is within the grid
                if (new_row >= 0 && new_row < n && new_col >= 0 && new_col < m)
                {   
                    // Compute the new cost. Add one to the cost if to reach to this location, sign change is required
                    int new_cost = cost + (i != (grid[row][col] - 1) ? 1 : 0);

                    // If the new cost computed is cheaper than previous computed cost, update the cost and push to the 'pq'.
                    if (min_cost[new_row][new_col] > new_cost)
                    {
                        min_cost[new_row][new_col] = new_cost;
                        pq.push({new_cost, new_row, new_col});
                    }
                }
            }
        }
        return min_cost[n - 1][m - 1];
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/solutions/6294035/minimum-cost-to-make-at-least-one-valid-path-in-a-grid
*/
