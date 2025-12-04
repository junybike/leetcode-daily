// 2025 Mar 1

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {        
        int n = nums.size();    // size of 'nums'
        vector<int> ans;        // the vector to return

        // Applying the operations directly to 'nums'
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] == nums[i + 1]) 
            {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        // Count number of zeros in 'nums' and push values that aren't zero to 'ans'
        int zeros = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i]) ans.push_back(nums[i]);
            else zeros++;
        }

        // Push the rest of zeros to the 'ans'
        for (int i = 0; i < zeros; i++)
        {
            ans.push_back(0);
        }
        
        return ans;   
    }
};
