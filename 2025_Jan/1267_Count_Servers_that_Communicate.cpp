// 2025 Jan 24

class Solution {
public:
    int countServers(vector<vector<int>>& grid) 
    {
        int row = grid.size();      // The number of rows in 'grid'
        int col = grid[1].size();   // The number of cols in 'grid'
        int servers = 0;            // The number of servers connected

        vector<pair<int, int>> locations;   // Stores all locations of servers in 'grid'
        vector<int> map_row(row, 0);        // Stores how many servers are present in each rows
        vector<int> map_col(col, 0);        // Stores how many servers are present in each cols

        // Find all server locations and record 'map_row' and 'map_col'
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j]) 
                {
                    locations.push_back({i, j});
                    map_row[i]++;
                    map_col[j]++;
                }
            }
        }

        // For each servers, if one of their row or col location has more than one server,
        // add one to the 'servers'
        for (auto& i : locations)
        {
            if (map_row[i.first] > 1 || map_col[i.second] > 1) servers++;
        }
        
        return servers;
    }
};
