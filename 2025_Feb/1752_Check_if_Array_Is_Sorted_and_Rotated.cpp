// 2025 Feb 2

class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int n = nums.size();    // Size of 'nums'
        bool rotate = false;    // Set it true if nums is possibly rotated

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1]) // If some part in 'nums' is not ascending,
            {
                if (!rotate) rotate = true; // If 'rotate' is not false, set rotate to true
                else return false;          // If 'rotate' is already true, the array is not valid
            }
        }

        // If array is marked as 'rotate' and value at nums[0] is lower than nums[n - 1], array is sorted but rotated.
        // example: ... nums[n - 2], nums[n - 1], nums[0], nums[1], ...
        if (rotate && nums[0] < nums[n - 1]) return false;
        return true;
    }
};
