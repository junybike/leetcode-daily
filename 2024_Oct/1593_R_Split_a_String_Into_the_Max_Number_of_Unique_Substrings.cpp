class Solution {
public:

    unordered_set<string_view> word;    // To store the substrings
    char n = 0;                         // size of string s
    char maxcnt = 0;                    // max count of substrings

    void backtrack(char c, char cnt, string_view s)
    {
        // If (size of string - the index of string) is less or equal to (max count of substrings - current count of substrings)
        // not possible to improve the max count of substrings. Therefore, cancel the backtracking.
        if (n - c <= maxcnt - cnt) return;
        
        // When the index of string reached to the end of string, check max count of substrings and update.
        if (c >= n)
        {
            maxcnt = max(maxcnt, cnt);
            return;
        }

        for (char j = c; j < n; j++)
        {
            string_view temp = s.substr(c, j - c + 1);

            // Case where the string 'temp' is already seen before. 
            if (word.count(temp)) continue;

            // Insert the string 'temp' if it hasn't been seen before.
            // Backtrack again from here to find max number of substrings of string 'temp'.
            word.insert(temp);
            backtrack(j + 1, cnt + 1, s);
            word.erase(temp);
        }
    }

    int maxUniqueSplit(string& s) 
    {
        n = s.size();
        word.reserve(n);

        char cnt = 0;
        backtrack(0, cnt, string_view(s));

        return maxcnt;
    }
};

/*
Solution reference
https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/solutions/5945169/backtracking-hash-set-over-string-string-view-prune-12ms-beats-99-71
*/
