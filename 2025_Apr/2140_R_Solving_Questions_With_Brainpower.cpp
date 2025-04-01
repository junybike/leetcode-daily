// 2025 Apr 1

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) 
    {
        int n = questions.size();   // number of values in questions
        vector<long long> dp(n);    // keep track of possible points at a certain question

        dp[n - 1] = questions[n - 1][0];    // base case. 
        for (int i = n - 2; i >= 0; i--)
        {
            int skip = questions[i][1];     // number of questions needed to skip if we solve current question
            dp[i] = questions[i][0];        // stores the point it can obtain by solving current question

            // if we can still solve a question after skipping this question, 
            // add the point we can get after solving the next question it can solve after skipping
            if (i + skip < n - 1) dp[i] += dp[i + skip + 1];

            // if solving the next question instead of solving current question gets larger point, 
            // mark it to skip the current question     
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};

/*
solution reference
https://leetcode.com/problems/solving-questions-with-brainpower/solutions/6601501/recursive-iterative-dp-c-c-beats-100-py3
*/
