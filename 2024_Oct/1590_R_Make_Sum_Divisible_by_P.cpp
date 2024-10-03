// 2024 Oct 3

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) 
    {
        // Get the total sum of values in nums
        long total = 0;
        for (int num : nums) 
        {
            total += num;
        }

        // The remainder when total is divided by p.
        // If the remainder is 0, no need to remove any values to make it divisible by p
        int remain = total % p;
        if (remain == 0) return 0;

        unordered_map<int, int> umap;  // Stores prefix mod
        umap[0] = -1;                  // Initialize for handling full prefix
        long prefix_sum = 0;           // Sum of prefixes
        int min_length = nums.size();  // The length of minimum subarray that can be removed

        for (int i = 0; i < nums.size(); ++i) 
        {
            prefix_sum += nums[i];                           // Adds up the sum of prefixes each iteration
            int current_mod = prefix_sum % p;                // Current sum of prefixes remainder when divided by p
            int target_mod = (current_mod - remain + p) % p; // The value that needs to remove 

            // If one of subarray of sum is equal to the target_mod, return the length of that subarray. 
            if (umap.find(target_mod) != umap.end()) 
            {
                min_length = min(min_length, i - umap[target_mod]);
            }
            // Store current subarray length
            umap[current_mod] = i;
        }
        // If the length of minimum length remained same as nums length, not possible. Return -1.
        // Else, return the minimum length.
        if (min_length == nums.size()) return -1;
        return min_length;
    }
};

/*
Solution reference
https://leetcode.com/problems/make-sum-divisible-by-p/solutions/5862793/fastest-way-to-make-sum-divisible-by-p-in-multiple-languages
*/
