// 2024 Dec 29

class Solution {
public:

    long getwords(vector<string>& words, string& target, int w_index, int t_index, vector<vector<int>>& dp, vector<vector<int>>& freq)
    {
        // All characters of the target matches
        if (t_index == target.length()) return 1;

        // The target cannot be formed
        if (w_index == words[0].size() || words[0].size() - w_index < target.length() - t_index) return 0;
        
        // There already exists a match for this character in 'target'
        if (dp[w_index][t_index] != -1) return dp[w_index][t_index];

        long count = 0;                     // Possible ways to form the 'target'
        int index = target[t_index] - 'a';  // The location of this character in 'target' 

        // Sum up the possible ways of forming 'target' by using the same 'target' index with the next character in the word in 'words'
        count += getwords(words, target, w_index + 1, t_index, dp, freq);

        // Sum up the all possible ways of forming 'target' with duplicated location & character 
        count += freq[w_index][index] * getwords(words, target, w_index + 1, t_index + 1, dp, freq);

        return dp[w_index][t_index] = count % 1000000007;
    }

    int numWays(vector<string>& words, string target) 
    {
        int n = words.size();           // Number of word in 'words'
        int t_size = target.length();   // The size of target
        int w_size = words[0].size();   // The size of each word in 'words'

        vector<vector<int>> dp(w_size, vector<int>(t_size, -1));    // 
        vector<vector<int>> freq(w_size, vector<int>(26, 0));       // Stores each characters frequency in all word in 'words'

        // Initializing the 'freq'
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < w_size; j++)
            {
                freq[j][words[i][j] - 'a']++;
            }
        }

        return getwords(words, target, 0, 0, dp, freq);
    }
};

/*
solution reference
https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/solutions/6157497/number-of-ways-to-form-a-target-string-given-a-dictionary
*/
