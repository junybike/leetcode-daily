// 2025 Jan 2

class Solution {
public:

    // Check if a character is a vowel
    bool check(char& a)
    {
        return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) 
    {
        int n = words.size();   // The number of words in 'words'
        vector<int> psum;       // Prefix sum of words that starts and ends with a vowel. Ex: At index 3, it holds how many words are there so far that starts and ends with a vowel 
        vector<int> ans;        // Records the amount of the "vowel words" in this range of 'queries' 

        // Computes the prefix sum of the words
        psum.push_back(check(words[0][0]) && check(words[0].back()));
        for (int i = 1; i < n; i++)
        {
            psum.push_back(psum[i - 1] + (check(words[i][0]) && check(words[i].back())));
        }

        // For each ranges in 'queries', compute how many "vowel words" are present by subtracting prefix sum of the end of range and start of range.
        for (auto& q : queries)
        {
            if (q[0] == 0) ans.push_back(psum[q[1]]);
            else ans.push_back(psum[q[1]] - psum[q[0] - 1]);
        }

        return ans; 
    }
};
