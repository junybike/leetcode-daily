// 2025 May 16

class Solution {
public:

    // check if the two strings are different by one character
    bool check(string& s1, string& s2)
    {
        if (s1.size() != s2.size()) return false;
        
        int diff = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            diff += (s1[i] != s2[i]);
            if (diff > 1) return false;
        }
        return (diff == 1);
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        int n = groups.size();      // size of groups
        vector<int> dp(n, 1);       // dp[i] records longest subsequence ending at index i
        vector<int> prev(n, -1);    // dp[i] records previous index in longest subsequence ending at i

        int maxIndex = 0;           // keep track of the index for longest subsequence
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (check(words[i], words[j]) && (dp[j] + 1 > dp[i]) && (groups[i] != groups[j]))
                {
                    dp[i] = dp[j] + 1;  // record the length of subsequence
                    prev[i] = j;        // record the previous index
                }
            }
            if (dp[i] > dp[maxIndex]) maxIndex = i; // updates the index that holds the longest subsequence
        }

        // add the strings to the vector from the back of the 'words'
        vector<string> ans;
        for (int i = maxIndex; i >= 0; i = prev[i])
        {
            ans.push_back(words[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/editorial
*/
