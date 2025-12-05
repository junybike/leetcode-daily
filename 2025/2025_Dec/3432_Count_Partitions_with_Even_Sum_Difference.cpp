// 2025 Dec 5
class Solution {
public:
    int countPartitions(vector<int>& nums) 
    {
        int sumL = nums[0]; // sum of left sub partition
        int sumR = 0;       // sum of right sub partition
        int ans = 0;

        for (int i = 1; i < nums.size(); i++) // sum up for the right sub partition
        {
            sumR += nums[i];
        }    

        // add each values in num to left sub partition and subtract it from right sub partition
        for (int i = 1; i < nums.size(); i++) 
        {
            int val = nums[i];
            sumL += val;
            sumR -= val;
            
            if ((sumL - sumR) % 2 == 0) ans++;
        }
        return ans;
    }
};
