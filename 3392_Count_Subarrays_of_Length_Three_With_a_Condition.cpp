// 2025 Apr 27

class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int cnt = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            // for each subarray of 3, check if (sum of first and last value in subarray) / 2 is equal to middle value in subarray
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i]) cnt++;
        }
        return cnt;
    }
};
