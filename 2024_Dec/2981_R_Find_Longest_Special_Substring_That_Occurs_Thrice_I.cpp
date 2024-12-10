// 2024 Dec 10

class Solution {
public:

    bool s_search(string s, int n, int M)
    {
        vector<int> cnt(26, 0); // Records the amount of each characters encountered in 's'
        int index = 0;          // An index indicator in 's'

        for (int i = 0; i < n; i++)
        {
            // Increment 'index' whenever current character is not the same as character at s[index];
            while (s[index] != s[i]) index++;            

            // If the length of special substring of s[i] is at least 'M', 
            // increment the s[i] to indicate that s[i] kind of subsequence exists. 
            if (i - index + 1 >= M) cnt[s[i] - 'a']++;

            // If the special subsequence occurs at least 3 times, return true.
            if (cnt[s[i] - 'a'] > 2) return true;
        }
        return false;
    }

    int maximumLength(string s) 
    {
        int n = s.length(); // Size of 's' 
        int L = 1;          // Smallest size of substring possible
        int R = n;          // Largest size of substring possible

        // Case where 's' does not contain 3 same characters. (no special substring that occurs at least thrice)
        if (!s_search(s, n, L)) return -1;  

        // Binary search: Finding the maximum length of special substring that occurs at least thrice
        while (L + 1 < R)
        {
            int M = (L + R) / 2;    // Middle value of size 'L' and 'R'.  
            
            // If there is a special substring of length 'M' that occurs at least thrice,
            // set the minimum length of the subsequence (L) to 'M'.
            // Else, set the maximum length of subsequence (R) to 'M'.
            if (s_search(s, n, M)) L = M;     
            else R = M;
        }
        
        return L;
    }
};
/*
solution reference
https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/solutions/6130737/simple-binary-search-100-beats
*/
