// 2025 Apr 8

class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int freq[101] = {0};    // store values encountered in 'nums'
        int index = -1;         // the latest index where duplicate value appears
        
        for (int i = nums.size() - 1; i >= 0; i--)  // find the latest index where duplicate value appears
        {
            freq[nums[i]]++;
            if (freq[nums[i]] > 1) 
            {
                index = i;
                break;
            }
        }   
        return ceil(double(index + 1) / 3);         // minimum number of operation needed to remove upto the 'index'
    }
};
