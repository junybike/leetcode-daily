// 2025 June 12
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) 
    {
        int n = nums.size();    
        int ans = INT_MIN;      // maximum difference to return
        
        for (int i = 0; i < nums.size(); i++)
        {
            int cur = 0;

            // If at the end of vector, check the last and first element's difference
            if (i == n - 1) cur = max(nums[i] - nums[0], nums[0] - nums[i]); 
            else cur = max(nums[i] - nums[i + 1], nums[i + 1] - nums[i]); 
            
            if (cur > ans) ans = cur;   // update the max difference
        }
        return ans;
    }
};
