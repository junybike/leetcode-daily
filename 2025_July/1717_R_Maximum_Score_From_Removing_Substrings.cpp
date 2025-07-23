// 2025 July 23

class Solution {
public:
    int maximumGain(string s, int x, int y) 
    {
        if (x < y)  // to keep x to hold the larger value
        {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int acnt = 0;   // counts number of 'a' encountered
        int bcnt = 0;   // counts number of 'b' encountered
        int points = 0; // tracks the score from removing substrings

        for (int i = 0; i < s.size(); i++)
        {
            char cur = s[i];        
            if (cur == 'a') acnt++; // current character is 'a'
            else if (cur == 'b')    // current character is 'b
            {
                if (acnt > 0)   // if there was 'a' before, sum up the point for substring "ab"
                {
                    acnt--;
                    points += x;
                }
                else bcnt++;
            }
            else    // current character is not a and b
            {
                points += min(bcnt, acnt) * y;  // if both a and b were present just before this character, sum up the point for substring "ba"
                acnt = bcnt = 0;    // reset count
            }
        }

        points += min(bcnt, acnt) * y;
        return points;
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-score-from-removing-substrings/editorial
*/
