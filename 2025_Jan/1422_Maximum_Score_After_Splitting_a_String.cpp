// 2025 Jan 1

class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.length(); // The size of 's'
        int L = 0;          // The score of left side substring
        int R = 0;          // The score of right side substring

        // Initially, the substrings are size 1 left and n - 1 right.
        // Determine if first value at 's' is 0 or 1.
        if (s[0] == '0') L++;   

        // Determine the right side score
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1') R++; 
        }    
       
        int ans = L + R;    // The total score of both side

        // From right substring, move values one by one and update both side's score.
        // Check if the sum of both side is greater than 'ans'. Update 'ans' when new L + R is larger than 'ans' 
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == '0') L++;
            if (s[i] == '1') R--;
            if (L + R > ans) ans = L + R;
        }

        return ans;
    }
};
