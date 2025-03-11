// 2025 Mar 11

class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n = s.length();     // length of 's'
        int L = 0;              // left end of window
        int R = 0;              // right end of window

        vector<int> freq(3, 0);         // to store the frequency of a, b, c in 's'
        int ans = 0;                    // number of substring to return

        while (R < n)
        {
            freq[s[R] - 'a']++;         // record the char at right end of window
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
            {
                ans += n - R;           // all substrings from current window to the end are valid
                freq[s[L] - 'a']--;     // remove the char at left end of window 
                L++;                    // moving the window range by increasing the left end
            }
            R++;                        // moving the window range by increasing the right end
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/editorial
*/
