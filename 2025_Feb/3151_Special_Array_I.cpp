// 2025 Feb 1

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) 
    {
        int temp = nums[0]; // stores previous value
        for (int i = 1; i < nums.size(); i++)
        {
            // If the two adjacent values' parity are same, array is not special. 
            if (nums[i] % 2 == temp % 2) return false;  
            temp = nums[i]; // update the previous value
        }
        return true;
    }
};
