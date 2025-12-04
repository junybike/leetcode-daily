// 2025 Jan 10

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        // Contains the max frequency of characters from words from 'words2'
        // For example, for characters[0], if some word is aaa... and other word is aaaa...
        // then characters[0] would hold 4.
        int characters[26] = {0};   
        
        // The list of words from 'words1' that satisfy the condition
        vector<string> ans;

        // Compute 'characters'
        for (string& s : words2)
        {
            int freq[26] = {0}; // frequency of characters for string 's'
            for (char& c : s)
            {
                // If the frequency for this character is larger than the 'characters', replace. 
                freq[c - 'a']++;
                if (freq[c - 'a'] > characters[c - 'a']) characters[c - 'a'] = freq[c - 'a'];
            }
        }

        // Find the words that satisfy the conditions
        for (string& s : words1)
        {
            int freq[26] = {0};     // Frequency of characters for string 's'
            bool valid = true;      // Indicate if this character is a valid word

            // Compute the characters frequency
            for (char& c : s)
            {
                freq[c - 'a']++;
            }

            // Compare if a character's frequency in 'characters' is larger than the frequency that 'freq' is holding.
            // If larger, this word does not satisfy the condition.
            // Set valid to false.
            for (int i = 0; i < 26; i++)
            {
                if (characters[i] > freq[i]) 
                {
                    valid = false;
                    break;
                }
            }

            if (valid) ans.push_back(s);
        }
        return ans;
    }
};
