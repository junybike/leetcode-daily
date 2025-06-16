// 2025 June 16
class Solution {
public:
    int maximumDifference(vector<int>& nums) 
    {
        int intmin = INT_MAX;   // keep track of minimum value as iterate through nums
        int ans = INT_MIN;      // keep track of the max diff

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < intmin) intmin = nums[i]; // update minimum value
            
            int cur = nums[i] - intmin; // current difference 
            if (cur > ans) ans = cur;   // check if current difference is greater than ans.
        }    
        return ans == 0 ? -1 : ans; // if ans is 0, not applicable. return -1.
    }
};
