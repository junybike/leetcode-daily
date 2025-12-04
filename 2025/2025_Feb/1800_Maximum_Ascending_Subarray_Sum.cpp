// 2025 Feb 4

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) 
    {
        short cur = nums[0];    // stores the current subarray sum in 'nums'
        short ans = nums[0];    // stores the maximum subarray sum in 'nums'

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] < nums[i + 1]) cur += nums[i + 1];  // if ascending, sum up the value nums[i + 1] to 'cur'
            else cur = nums[i + 1];                         // if not ascending, set 'cur' to current value nums[i + 1]

            if (cur > ans) ans = cur;                       // update 'ans' if 'cur' is larger than 'ans'
        }

        return ans;
    }
};
