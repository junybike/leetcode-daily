// 2024 Sept 01

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) 
    {        
        vector<vector<int>> array = {};
        int index = 0;

        // Impossible case: number of values is larger than size of 2D array.
        if (m * n < original.size() || m * n > original.size()) return array;

        // Append values into the 2D array. Switch to the next row when it is full.
        for (int i = 0; i < m; i++)
        {
            vector<int> subarray = {};
            for (int j = 0; j < n; j++)
            {
                subarray.emplace_back(original[index]);
                index++;
            }
            array.emplace_back(subarray);
        }
        return array;
    }
};
