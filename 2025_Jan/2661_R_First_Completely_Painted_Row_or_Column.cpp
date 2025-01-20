// 2025 Jan 20

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        int numRow = mat.size();                    // number of rows in 'mat'
        int numCol = mat[0].size();                 // number of cols in 'mat'
        vector<int> rowCount(numRow);               // keep track of how many grids in each row were iterated through
        vector<int> colCount(numCol);               // keep track of how many grids in each colume were iterated through

        unordered_map<int, pair<int, int>> umap;    // For each value in 'mat', assign its position in 'mat'

        // Assigning each value in 'mat' their position in 'mat' 
        for (int i = 0; i < numRow; i++)
        {
            for (int j = 0; j < numCol; j++)
            {
                int value = mat[i][j];
                umap[value] = {i, j};
            }
        }

        // Iterate values in order of arr
        for (int i = 0; i < arr.size(); i++)
        {
            int num = arr[i];              
            auto [row, col] = umap[num];    // The position of the current value
            
            rowCount[row]++;    // Increment the row of this position
            colCount[col]++;    // Increment the colume of this position

            // Check if all values in the row or colume were all painted
            if (rowCount[row] == numCol || colCount[col] == numRow) return i;   
        }

        return -1;
    }
};

/*
solution reference
https://leetcode.com/problems/first-completely-painted-row-or-column/solutions/6301353/first-completely-painted-row-or-column
*/
