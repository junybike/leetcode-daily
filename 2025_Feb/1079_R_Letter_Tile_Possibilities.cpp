class Solution {
public:

    int find_sequence(int freq[26])
    {
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0) continue;

            // Tries to use the current character as a sequence.
            // Increase the 'count' and decrement the frequency in the 'freq'.
            // Tries to build up sequence with 'freq' after the current character is used.
            count++;
            freq[i]--;
            count += find_sequence(freq);

            // restore the frequency
            freq[i]++;
        }
        return count;
    }

    int numTilePossibilities(string tiles) 
    {
        int freq[26] = {0};     // Stores the frequency of each characters in 'tiles'
        for (char c : tiles)    // Find the frequency of each characters in 'tiles'
        {
            freq[c - 'A']++;
        }

        return find_sequence(freq); // Backtracking
    }
};
/*
solution reference
https://leetcode.com/problems/letter-tile-possibilities/editorial
*/
