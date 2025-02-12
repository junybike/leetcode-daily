// 2025 Feb 12

class Solution {
public:

    // sum of each digits in an integer
    int sum_digit(int i)
    {
        if (i == 0) return 0;
        return (i % 10) + sum_digit(i / 10);
    }

    int maximumSum(vector<int>& nums) 
    {
        unordered_map<int, multiset<int, greater<int>>> sums;   // for each sum of digits, store its all original integer
        for (int& i : nums)
        {
            sums[sum_digit(i)].insert(i);   // for each integer in 'nums', calculate its digit sum
        }

        int ans = -1;       // record the max sum of pairs
        for (auto i : sums)
        {
            // For a digit sum, if it has at least 2 original integer stored,
            // check if the sum of two original integer is greater than ans. Update ans if it is greater. 
            if (i.second.size() > 1)
            {
                ans = max(ans, *next(i.second.begin(), 0) + *next(i.second.begin(), 1));
            }
        }

        return ans;
    }
};
