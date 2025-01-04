// 2025 Jan 4

class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int> first = vector(26, -1); // Index in 's' for first appearance of each characters
        vector<int> last = vector(26, -1);  // Index in 's' for last appearance of each characters

        // Find the first and last appearance in 's' for each characters
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;   // The first appearance
            last[c] = i;                        // Update the last appearance whenever the character is encountered
        }

        int ans = 0;    // The number of 3-palindromes
        for (int i = 0; i < 26; i++)
        {
            if (first[i] == -1) continue;   // Skip if this character never existed in 's'
            
            // Record unique characters in between the two same characters
            unordered_set<char> uset;       
            for (int j = first[i] + 1; j < last[i]; j++) 
            {
                uset.insert(s[j]);  
            }
            ans += uset.size(); // The number of unique characters in between the two same characters are equivalent to 3-palindromes that starts and ends with the same character
        }

        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/unique-length-3-palindromic-subsequences/solutions/4190834/unique-length-3-palindromic-subsequences
*/
