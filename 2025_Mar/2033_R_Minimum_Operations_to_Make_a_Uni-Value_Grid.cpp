// 2025 Mar 26

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int> vals;
        int ans = 0;

        // makes 1D array by brining all elements from 'grid'
        for (auto& arr : grid)
        {
            for (int i : arr)
            {
                vals.push_back(i);
            }
        }
        int n = vals.size();    // size of 'vals'
        
        // Partially sorted. The median element is placed at middle index
        nth_element(vals.begin(), vals.begin() + n / 2, vals.end());
        
        // The median element is the number that all element must make themselves equal to
        int commonNum = vals[n / 2];

        for (int i : vals)
        {
            if (i % x != commonNum % x) return -1;  // different remainder -> not possible
            ans += abs(commonNum - i) / x;
        }    
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/editorial
*/
