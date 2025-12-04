// 2025 Feb 5

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        pair<char, char> de = {'?', '?'};   // a pair of ?
        pair<char, char> sw1 = {'?', '?'};  // to store a pair of character at some index i where 's1' and 's2' have different character
        pair<char, char> sw2 = {'?', '?'};  // to store a pair of character at some index j where 's1' and 's2' have different character (i < j)

        for (int i = 0; i < s1.length(); i++)
        {
            // if at an index, 's1' and 's2' characters arent equal, store the two character in 'sw1'.
            if (s1[i] != s2[i] && sw1 == de)
            {
                sw1 = {s1[i], s2[i]};
            }
            // if sw1 is not a pair of ? and theres another index where s1 and s2 characters arent equal, store the two character in 'sw2'.
            else if (s1[i] != s2[i] && sw2 == de) 
            {
                sw2 = {s2[i], s1[i]};
            }
            // if 'sw1' and 'sw2' are both not a pair of ? and encounters another inequal characters from 's1' and 's2' at some index, return false. (requires more than 1 swap)
            else if (s1[i] != s2[i] && sw2 != de && sw1 != de) 
            {
                return false;
            }
        }    

        // If sw1 and sw2 stores same pair of character, two strings are equal with at most one swap
        if (sw1 == sw2) return true;
        return false;
    }
};
