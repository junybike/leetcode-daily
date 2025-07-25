// 2025 July 25
class Solution {
public:
    int maxSum(vector<int>& nums) 
    {
        int freq[201];      // to check if value exists in nums. (if freq[i] != 0, i exists in nums)
        for (int i : nums)
        {
            freq[i + 100]++;
        }

        long long cnt = INT_MIN;        // to keep track of max sum
        for (int i = 0; i < 201; i++)
        {
            if (freq[i] == 0) continue; // if i doesnt exists, skip.
            cnt = max((long long)(i - 100), cnt + (i - 100));   // compare to find the max sum
        }

        return cnt;
    }
};
