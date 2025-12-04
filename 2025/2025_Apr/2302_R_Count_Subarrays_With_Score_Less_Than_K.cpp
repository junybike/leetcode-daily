// 2025 Apr 28

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int n = nums.size();
        long long cnt = 0;
        long long ans = 0;

        for (int i = 0, j = 0; j < n; j++)
        {
            cnt += nums[j];
            
            // subtract the values from the left end if the subarray doesnt meet the requirement and increment the left end point
            while (i <= j && cnt * (j - i + 1) >= k)    
            {   
                cnt -= nums[i];
                i++;
            }
            // sum up the length of subarray to ans as counting the subarray
            ans += j - i + 1;
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/count-subarrays-with-score-less-than-k/editorial
*/
