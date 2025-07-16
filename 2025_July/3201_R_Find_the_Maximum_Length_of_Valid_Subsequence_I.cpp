// 2025 July 16
class Solution {
public:
    int maximumLength(vector<int>& nums) 
    {
        // 4 different types of pattern to consider
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        int ans = 0;

        for (auto& p : patterns)    // try each pattern and find the greatest
        {
            int cnt = 0;
            for (int i : nums)
            {
                if (i % 2 == p[cnt % 2]) cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/editorial
*/
