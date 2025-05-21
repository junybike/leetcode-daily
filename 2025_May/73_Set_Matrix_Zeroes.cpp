// 2025 May 21
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<pair<int, int>> locations;   // store the locations of zeros in matrix

        for (int i = 0; i < n; i++) // find the locations of zeros in matrix
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0) locations.push_back({i, j}); 
            }
        }    
        for (auto& pos : locations)     // visit each zeros and change its all values in its row and col to zero
        {
            for (int x = 0; x < n; x++)
            {
                matrix[x][pos.second] = 0;
            }
            for (int y = 0; y < m; y++)
            {
                matrix[pos.first][y] = 0;
            }
        }
    }
};
