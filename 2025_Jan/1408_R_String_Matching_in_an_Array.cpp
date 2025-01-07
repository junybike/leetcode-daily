// 2025 Jan 7

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        // Sort the 'words' with respect to the word length. Shortest word first. 
        sort(words.begin(), words.end(), [](const string& s, const string& t) {return s.size() < t.size();});
        
        int n = words.size();   // The number of strings in 'words'
        vector<string> ans;     // A vector to store substrings.

        for (int i = 0; i < n; i++)
        {
            string& target = words[i];    // The string to find.

            for (int j = i + 1; j < n; j++)
            {
                string& word = words[j];        // A string that has greater or equal length than target. 
                if (word.find(target) != -1)    // If a word contains a substring identical to target, store the target to 'ans'. Move on to next target
                {
                    ans.push_back(target);
                    break;
                }
            }
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/string-matching-in-an-array/solutions/6241837/sort-wrt-len-then-find-beats-100
*/
