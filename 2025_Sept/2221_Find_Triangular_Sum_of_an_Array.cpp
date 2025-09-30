// 2025 Sept 30

class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int n = nums.size();

        for (int j = 0; j < n; j++)
        {
            vector<int> sum;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                sum.push_back((nums[i] + nums[i + 1]) % 10);
            }    
            nums = sum;
        }
        return nums[0];
    }
};

class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int n = nums.size();

        while (n > 1)
        {
            for (int i = 0; i < nums.size() - 1; i++)
            {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            nums.pop_back();
            n--;
        }
        return nums[0];
    }
};

