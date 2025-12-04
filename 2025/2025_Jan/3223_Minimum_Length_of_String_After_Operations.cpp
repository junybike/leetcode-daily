// 2025 Jan 13

class Solution {
public:
    int minimumLength(string s) 
    {
        int freq[26] = {0}; // Record the frequency of characters in 's'
        int ans = 0;        // Record the minimum length of string after operations

        // Compute the frequency of characters in 's'
        for (char& c : s)
        {
            freq[c - 'a']++;
        }    
        
        // Reducing the size of 's'
        for (int i = 0; i < 26; i++)
        {
            // If a character's frequency is an odd number and has at least 3 occurance,
            // it can be reduced to 1 occurance.
            if (freq[i] % 2 != 0 && freq[i] >= 3) ans += 1;

            // If a character's frequency is an even number and has at least 2 occurance, 
            // it can be reduced to 1 occurance. 
            else if (freq[i] >= 2) ans += 2;

            // In any other cases, frequency is 1. Therefore, cannot be reduced.
            else ans += freq[i]; 
        }
        return ans;
    }
};
