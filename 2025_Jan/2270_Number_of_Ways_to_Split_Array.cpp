// 2025 Jan 3

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        long long Lsum = 0;  // To record the sum of values on the left subarray 
        long long Rsum = 0;  // To record the sum of values on the right subarray

        // Initially, set the 'Rsum' to hold the sum of whole values in 'nums'
        for (int i : nums)
        {
            Rsum += i;
        }

        int ans = 0;  // To record the valid ways to split the array
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // Move each values from the right subarray to the left subarray
            Rsum -= nums[i];  
            Lsum += nums[i];

            // Check the sum of both subarray and determine if it is a valid split
            if (Lsum >= Rsum) ans++;
        }
        return ans;
    }
};
