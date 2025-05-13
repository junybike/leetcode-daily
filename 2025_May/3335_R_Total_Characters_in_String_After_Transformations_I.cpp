// 2025 May 13
class Solution {
public:
    int lengthAfterTransformations(string s, int t) 
    {
        vector<int> freq(26);   // keeps the frequencies of each characters in s
        for (char c : s)
        {
            freq[c - 'a']++;
        }    

        for (int i = 0; i < t; i++)
        {
            vector<int> next(26);   // for each iteration, update the freq vector with 'next'   
            
            // case for z -> ab
            next[0] = freq[25];
            next[1] = (freq[25] + freq[0]) % 1000000007;

            // transformation for b to z
            for (int i = 2; i < 26; i++)
            {
                next[i] = freq[i - 1];
            }
            freq = next;    // update the freq vector
        }

        int ans = 0;    // the string length
        for (int i : freq)
        {
            ans = (ans + i) % 1000000007;
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/total-characters-in-string-after-transformations-i/editorial
*/
