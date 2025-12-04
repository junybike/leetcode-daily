// 2025 March 3

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int> less;       // stores all values in 'nums' less than or equal to 'pivot'
        vector<int> greater;    // stores all values in 'nums' greater than 'pivot'
        int cnt = 0;            // counts number of values in 'nums' same as 'pivot'

        for (int i : nums)
        {
            if (i < pivot) less.push_back(i);           // value less than 'pivot'
            else if (i > pivot) greater.push_back(i);   // value greater than 'pivot'
            else cnt++;                                 // number of values equal to 'pivot'
        }

        for (int i = 0; i < cnt; i++)   // append the values equal to 'pivot'
        {
            less.push_back(pivot);
        }

        // append 'greater' vector to 'less' vector
        less.insert(less.end(), greater.begin(), greater.end());
        return less;
    }
};
