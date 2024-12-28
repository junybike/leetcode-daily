// 2024 Dec 28

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();                    // Size of 'nums'
        vector<int> ksum(n - k + 1, 0);         // Stores the sum of values in subarrays from 'nums' with lenght of k.
        vector<int> list_L(n - 3 * k + 1, -1);  // Stores the leftmost three subarrays from 'nums'

        int max_sum = accumulate(nums.begin(), nums.begin() + k, 0);    // The sum of first k length subarray in 'nums'
        ksum[0] = max_sum;                                              // Stores it to first 'ksum' value
        list_L[0] = 0;                                                  // Stores its subarray starting index in 'nums'

        for (int i = 1; i < n - k + 1; i++)
        {
            ksum[i] = ksum[i - 1] - nums[i - 1] + nums[i + k - 1];  // Setting 'ksum' with sum of values in subarrays 
            if (i > n - 3 * k) continue;                            

            // Replace the 'max_sum' if a sum of values in subarray is larger. 
            // Keep track of its subarray location in 'nums' by storing it in 'list_L'.
            // Else, use the previous index of the max_sum for current iteration.
            if (max_sum < ksum[i])
            {
                max_sum = ksum[i];
                list_L[i] = i;
            }
            else list_L[i] = list_L[i - 1];
        }

        vector<int> list_R(n - 3 * k + 1, -1);  // Stores the leftmost three subarrays from 'nums'
        max_sum = ksum.back();                  // Set the 'max_sum' with the last subarray's sum in 'ksum'
        list_R.back() = n - k;                  // Stores the location (index) of the last subarray's sum in 'ksum' in 'nums'

        for (int i = n - k - 1; i >= 2 * k; i--)
        {
            // Replace the 'max_sum' if a sum of values in subarray is larger. 
            // Keep track of its subarray location in 'nums' by storing it in 'list_R'.
            // Else, use the previous index of the max_sum for current iteration.
            if (max_sum <= ksum[i])
            {
                max_sum = ksum[i];
                list_R[i - 2 * k] = i;
            }
            else list_R[i - 2 * k] = list_R[i + 1 - 2 * k];
        }

        vector<int> ans(3, -1);                 // The maximum sum of 3 non overlapping subarrays' index in 'nums' to return
        int max3k = 0;                          // Keep track of the maximum sum of 3 non overlapping subarrays.
        for (int i = 0; i <= n - 3 * k; i++)
        {
            // Compare a sum of 3 non overlapping subarrays.
            // Replace the 'ans' and 'max3k' if a greater sum is found.
            int sum = ksum[list_L[i]] + ksum[i + k] + ksum[list_R[i]];
            if (sum > max3k)
            {
                max3k = sum;
                ans = {list_L[i], i + k, list_R[i]};
            }
        }

        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/solutions/6195326/sliding-window-for-k-sum-dp-for-left-right-indices-beats-100
*/
