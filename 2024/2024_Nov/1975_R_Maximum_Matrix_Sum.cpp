// 2024 Nov 24

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long ans = 0;      // The sum of all values in 'matrix' to return
        int minval = INT_MAX;   // The minimum value in 'matrix'
        bool neg = false;       // Indicates if there is a negative value at the end.

        for (auto& arr : matrix)
        {
            for (int i : arr)
            {
                if (minval > abs(i)) minval = abs(i);   // Updates the minimum value in 'matrix'
                
                // If the value is negative, negate the 'neg' sign.
                // Add 'i' to 'ans' but in positive value. (subtracting a negative value)
                if (i < 0) 
                {
                    ans -= i;       
                    neg = !neg;
                }

                // Add 'i' to 'ans'
                else ans += i;
            }
        }

        // If, at the end, contains a negative value, subtract 2 * minimul value in 'matrix', 
        // since the value is added to the 'ans'. It must have subtracted without it getting added.
        // If not, just return the 'ans'

        return neg ? ans - 2 * minval : ans;
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-matrix-sum/solutions/6077057/find-the-min-of-absolute-values-beats-100
*/
