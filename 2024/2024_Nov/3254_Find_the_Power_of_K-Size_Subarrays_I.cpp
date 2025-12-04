// 2024 Nov 16

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {               
        int ans_n = nums.size() - k + 1;    // The size of 'ans' vector. Number of subarrays.
        vector<int> ans(ans_n, 0);          // The vector to return. Contains power of all subarrays.

        // Performs sliding window for each subarrays.
        for (int i = 0; i < ans_n; i++)
        {
            // The first value of the ith subarray.
            int L = i;

            // Check k number of values including L.
            // If the values are not consecutive, set L to -1 and stop the loop.
            // Else, continue check all k number of values.

            while (L < k + i - 1 && L != -1)
            {
                if (nums[L + 1] - nums[L] == 1) L++;
                else L = -1;
            }

            // If L is -1, then the values in this subarray is not consecutive. 
            // Set the power of this subarray -1.
            // Else, set the power of this subarray the last value of the subarray. 
            
            if (L == -1) ans[i] = -1;
            else ans[i] = nums[L];
        }
        return ans;  
    }
};
