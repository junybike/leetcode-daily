// 2025 May 17
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int col[3] = {0};   // stores frequency of each colors
        int index = 0;      // to traverse 'nums'

        for (int i : nums)  // find frequencies for each colors
        {
            col[i]++;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < col[i]; j++)    // overwrite color starting from 'color 0'
            {
                nums[index] = i;    
                index++;
            }
        }
    }
};
