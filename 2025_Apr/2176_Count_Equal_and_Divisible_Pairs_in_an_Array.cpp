class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
        int n = nums.size();    // nums size
        int cnt = 0;            // number of valid pairs

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // check if two numbers are equal and product of their indexs are divisible by k
                if (nums[i] == nums[j])
                {
                    if ((i * j) % k == 0)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
