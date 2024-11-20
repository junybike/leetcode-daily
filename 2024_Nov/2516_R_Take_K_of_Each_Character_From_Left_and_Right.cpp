// 2024 Nov 20

class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        int n = s.length(); // the length of string 's'
        int abc[3];         // stores the frequency of character a, b, and c in 's'

        // Records the frequency of the characters in 's'
        for (char c : s)
        {
            abc[c - 'a']++;
        }       
        // If one of the frequency is less than 'k', return -1.
        if (abc[0] < k || abc[1] < k || abc[2] < k) return -1;

        int ans = INT_MAX;  // the minimum number of minutes to return
        int L = 0;          // An index starting at first value of 's' 
        
        for (int R = 0; R < n; R++)
        {
            // As it iterates, pretend that s[R] is not observed.
            // From the end of 's', values up to index R of 's' are considered
            abc[s[R] - 'a']--; 

            // If one of characters' frequency is below 'k',
            // re-read the value from the leftside of 's' and increment its frequency
            // until the frequency that is below 'k' reaches to 'k'. 
            while (*min_element(abc, abc + 3) < k)
            {
                abc[s[L] - 'a']++;
                L++;
            }

            // Update the lowest minute spent for reading all characters at least 'k' times
            // by summing up the values read from the leftside and right side in 's'.
            if (ans > n - (R - L + 1)) ans = n - (R - L + 1);
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/solutions/6063845/beats-100-video-full-explain-list-most-common-string-interview-problems
*/
