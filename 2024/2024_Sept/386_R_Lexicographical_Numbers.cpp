// 2024 Sept 21

class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int> ans;
        int cur = 1;

        for (int i = 1; i <= n; i++)
        {
            ans.push_back(cur);
            // If 'cur' * 10 is less than 'n', keep add the 'cur' * 10 to the ans vector
            if (cur * 10 <= n) cur *= 10;    
            // If 'cur' * 10 exceeds n, add cur + 1. And if 'cur' exceeds/reach n or last digit is 9, reduce it by factor of 10 
            else
            {
                while (cur >= n || cur % 10 == 9) cur /= 10;
                cur++;
            }
        }
        return ans;
    }
};
/*
Solution Reference
https://leetcode.com/problems/lexicographical-numbers/solutions/5813956/interviewers-expect-iterative-approach-lets-understand
*/
