// 2025 Apr 19
class Solution {
public:
    
    long long lower_bound(vector<int>& nums, int low, int hi, int val)
    {
        while (low <= hi)   // finds the max number of values within the range and greater or equal to the val
        {
            int mid = low + ((hi - low) / 2);
            if (nums[mid] >= val) hi = mid - 1;
            else low = mid + 1;
        }
        return low;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(), nums.end());     // sort 'nums'
        long long ans = 0;                  // ans
        int n = nums.size();                // 'nums' size

        for (int i = 0; i < n; i++)
        {
            int low = lower_bound(nums, i + 1, n - 1, lower - nums[i]);     // possible pairs with sum < lower
            int hi = lower_bound(nums, i + 1, n - 1, upper - nums[i] + 1);  // possible pairs with sum <= upper
            ans += 1LL * (hi - low);    // the difference gives valid ones within the range
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/count-the-number-of-fair-pairs/editorial
*/
