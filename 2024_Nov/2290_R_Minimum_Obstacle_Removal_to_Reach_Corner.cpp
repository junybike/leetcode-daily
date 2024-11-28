// 2024 Nov 28

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) 
    {
        int h = grid.size();        // Number of rows in 'grid' (height)
        int w = grid[0].size();     // Number of columns in 'grid' (width)

        deque<pair<int, int>> dq{{0, 0}};   // Empty cell gets added to the front and obstacle gets added to the back of the queue  
        vector<vector<int>> dist(h, vector<int>(w, INT_MAX));   // Stores minimum obstacles removed to reach to each cells.
        dist[0][0] = 0; // Set starting position 0 in 'dist', as obstacles are not need to be removed to reach the starting position.

        vector<int> dx = {1, -1, 0, 0};     // x-direction indicator 
        vector<int>  dy = {0, 0, 1, -1};

        while (!dq.empty())
        {
            // Get the first location that 'dq' has and remove it from 'dq'. 
            auto [x, y] = dq.front();   
            dq.pop_front();

            // From the location, check the surroundings. (N, W, S, E)
            for (int i = 0; i < 4; i++)
            {
                // (xi, yi) one of the surrounding of (x, y)
                int xi = x + dx[i];    // Get the x cord of one of the surrounding
                int yi = y + dy[i];    // Get the y cord of one of the surrounding
                
                // Check if (xi, yi) is within the limit of 'grid'
                if (xi >= 0 && yi >= 0 && xi < h && yi < w)
                {
                    // Accumulate the amount of obstacle needed to be broken to reach to (xi, yi)
                    int d = dist[x][y] + grid[xi][yi];  

                    // If the amount of obstacle needed to be broken to reach to (xi, yi) 
                    // is lower than the current stored amount, update the amount.
                    // And if (xi, yi) holds an obstacle, push this location back of the 'dq'.
                    // Else, push this location to the front of the 'dq'.
                    if (d < dist[xi][yi])
                    {
                        dist[xi][yi] = d;
                        grid[xi][yi] == 0 ? dq.push_front({xi, yi}) : dq.push_back({xi, yi});
                    }
                }
            }
        }
        return dist[h - 1][w - 1];  // Amount of obstacle needed to be broken to reach to the end.
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/solutions/6090237/o-m-n-c-95ms-beats-98-80-java-48ms-py3-beats-94-24-bfs-0-1-deque-optimization
*/
