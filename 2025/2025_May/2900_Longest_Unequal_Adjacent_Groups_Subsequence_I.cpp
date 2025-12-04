// 2025 May 15

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) 
    {
        vector<string> ans;         // to store the words
        ans.push_back(words[0]);    // store the first word in 'ans'

        for (int i = 1; i < words.size(); i++)  // if adjacent groups are unequal, add the word at index i in 'words'
        {
            if (groups[i] != groups[i - 1]) ans.push_back(words[i]);
        }
        return ans;
    }
};
