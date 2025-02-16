// 2025 Feb 16

class Solution {
public:

    bool largest_sequence(int index, vector<int>& sequence, vector<bool>& used, int n)
    {
        // Case where all position in 'sequence' are filled
        if (index == sequence.size()) return true;

        // Current index at the 'sequence' is already filled. Move onto the next index.
        if (sequence[index] != 0) return largest_sequence(index + 1, sequence, used, n);

        for (int i = n; i >= 1; i--)
        {
            if (used[i]) continue;  // Skip the numbers already used in 'sequence'
            used[i] = true;         // Set the current number as used.
            sequence[index] = i;    // Tries to put the 'i' to the current 'index' position in 'sequence'
            
            if (i == 1) // Tries to put value 1 in this 'index'
            {           // Moving onto the next index
                if (largest_sequence(index + 1, sequence, used, n)) return true;
            }
            // Tries to place at the two position if the two places are empty
            else if (index + i < sequence.size() && sequence[index + i] == 0)
            {
                sequence[index + i] = i;
                if (largest_sequence(index + 1, sequence, used, n)) return true;
                sequence[index + i] = 0;    // Restoring the value back after the backtracking
            }

            // Restoring the condition to previous.
            sequence[index] = 0;
            used[i] = false;
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) 
    {
        vector<int> sequence(2 * n - 1, 0); // The resulting sequence
        vector<bool> used(2 + 1, false);    // Keeping track of which numbers are used in 'sequence'

        largest_sequence(0, sequence, used, n); // constructing the 'sequence'
        return sequence;
    }
};

/*
solution reference
https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/editorial
*/
