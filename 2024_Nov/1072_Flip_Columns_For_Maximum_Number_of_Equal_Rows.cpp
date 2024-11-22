// 2024 Nov 22

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int n = matrix[0].size();           // The size of each bit vector in 'matrix'
        unordered_map<string, int> umap;    // Records the pattern each bit vector in 'matrix'
        int ans = 0;                      // Records the number of most common 

        for (auto& arr : matrix)
        {
            string bits = "";   // The bit pattern for the current bit array 'arr'
            int b = arr[0];     // The first bit of the current bit array 'arr'

            for (int i = 1; i < n; i++)
            {
                // If the current bit is the same as the first bit, append "a" on 'bits'
                // Else, append "b" on 'bits' 
                if (arr[i] == b) bits += "a";   
                else bits += "b";
            }
            
            // Record the bit pattern of the current bit array 'arr'
            // If the frequency of this bit pattern is larger than the 'ans', update count. 
            umap[bits]++;
            if (umap[bits] > ans) ans = umap[bits];
        }

        return ans;
    }
};
