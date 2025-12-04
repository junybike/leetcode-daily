// 2025 Mar 19

class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n = nums.size();    // number of values in 'nums'
        int cnt = 0;            // number of operations to make

        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == 0)   // if current value is 0, negate current value and the next 2 values
            {
                nums[i] = !nums[i];
                nums[i + 1] = !nums[i + 1];
                nums[i + 2] = !nums[i + 2];
                cnt++;
            }
        }    

        // if the last 3 values are all 1, return the 'cnt'. else, not possible.
        if (nums[n - 1] && nums[n - 2] && nums[n - 3]) return cnt;
        else return -1;
    }
};
