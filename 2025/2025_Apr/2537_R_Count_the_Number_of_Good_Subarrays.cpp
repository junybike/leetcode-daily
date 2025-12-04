// 2025 Apr 16
class Solution {
public:
    long long countGood(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int same = 0;
        int R = -1;

        // stores number of identical values as the range changes (between L and R)
        unordered_map<int, int> umap;   
        long long ans = 0;

        for (int L = 0; L < n; L++)
        {
            // until the subarray reaches k amount of good subarray or goes out of range of n
            while (same < k && R + 1 < n)   
            {
                R++;
                same += umap[nums[R]];  // to keep track of number of same values in range
                umap[nums[R]]++;        // records new value in the range
            }
            // if the previous subarray reached k amount of good subarray, update the 'ans'
            if (same >= k) ans += (n - R);  

            // update as L side is increasing. removes the value that got out of range
            umap[nums[L]]--;        
            same -= umap[nums[L]];
        }    
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/count-the-number-of-good-subarrays/editorial
*/
