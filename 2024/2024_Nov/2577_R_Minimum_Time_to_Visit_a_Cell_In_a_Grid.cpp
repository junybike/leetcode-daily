// 2024 Nov 29

class Solution {
public:

    using info = tuple<int, short, short>;  // contains time (t) and location (x, y)
    int dir[5] = {0, 1, 0, -1, 0};          // Direction vector 

    // To check if the position is outside of the limit (border) of grid
    inline static bool isOutside(short i, short j, short n, short m)
    {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    int minimumTime(vector<vector<int>>& grid) 
    {
        // Base case where visiting other cells from the starting point is not allowed.
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int h = grid.size();    // The amount of rows in 'grid'
        int w = grid[0].size(); // The amount of columns in 'grid'

        vector<vector<int>> time(h, vector<int>(w, INT_MAX));   // Stores the time at each location
        priority_queue<info, vector<info>, greater<info>> pq;   // Stores the info tuple for each location to process
        
        pq.emplace(0, 0, 0);    // Starting point (0, 0) at time 0.
        time[0][0] = 0;         // Set the time at the starting point as 0.

        while (!pq.empty())
        {
            // Gets the next value in the 'pq'.
            auto [t, i, j] = pq.top();
            pq.pop();

            // If the destination is reached, return its time
            if (i == h - 1 && j == w - 1) return t;

            for (int a = 0; a < 4; a++)
            {
                // Gets the adj location of the current location
                // If the adj location is outside the limit of 'grid', skip.
                int r = i + dir[a];       
                int s = j + dir[a + 1];
                if (isOutside(r, s, h, w)) continue;

                // Gets the minimum time to reach the adj location (r, s)
                // from the current location.
                int w = ((grid[r][s] - t) & 1) ? 0 : 1;
                int nexttime = max(t + 1, grid[r][s] + w);

                // If the new time computed is quicker than the time stored in 'time',
                // update the time of the adj location and store the location to 'pq' to process later. 
                if (nexttime < time[r][s])
                {
                    time[r][s] = nexttime;
                    pq.emplace(nexttime, r, s);
                }
            }
        }
        return -1;
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/solutions/6093154/dijkstra-s-algorithm-87ms-beats-100
*/
