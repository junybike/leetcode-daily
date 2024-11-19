// 2024 Nov 19

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> umap;   // Keep tracks of the value encountered in 'nums' vector
        int n = nums.size();            // Size of 'nums' vector

        long long ans = 0;  // The maximum sum to return
        long long sum = 0;  // The sum to compare with maximum sum (ans) 
        int dup = 0;        // Keep track of how many duplicate values were used in the sum

        // Calculate the sum of the first subarray
        for (int i = 0; i < k; i++)
        {
            umap[nums[i]]++;
            sum += nums[i];
            if (umap[nums[i]] == 2) dup++; // If there is duplicate of a kind, increase 'dup' 
        }
        if (dup == 0) ans = sum;    // If the 'sum' did not have a duplicate of a kind, assign it to 'ans'

        // Performs sliding window
        for (int L = 0, R = k; R < n; R++, L++)
        {  
            int tempL = umap[nums[L]];      // Keep track of the amount of nums[L] encountered
            int tempR = umap[nums[R]];      // Keep track of the amount of nums[R] encountered
            sum += nums[R] - nums[L];       // Subtract the first value added previously and add the next value of the last value added previously 

            umap[nums[L]]--;    // Subtract the amount encounter of first value added previously (num[L])   
            umap[nums[R]]++;    // Increment the amount encounter of last value added (nums[R]) 
            
            if (umap[nums[L]] <= 1 && tempL >= 2) dup--;    // If this particular type does not occur more than twice anymore, decrement 'dup'
            if (umap[nums[R]] > 1 && tempR <= 1) dup++;     // If this particular type occur more than twice from now, increment 'dup'

            // If the sum calculated in this iteration is larger than 'ans' and no dup are present, update the 'ans' with 'sum'
            if (ans < sum && dup == 0) ans = sum;            
        }
        return ans;
    }
};
