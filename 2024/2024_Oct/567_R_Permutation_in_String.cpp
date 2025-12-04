//2024 Oct 4

class Solution {
public:

    // Function to check if all value in int array are zeros
    bool allzero(int* arr)
    {
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] != 0) return false;
        }
        return true;
    }   

    bool checkInclusion(string s1, string s2) 
    {
        int arr[26] = {0};    // To count each character's appearance in s1 
        int m = s1.length();  // s1 length
        int n = s2.length();  // s2 length

        // Count each character's appearance in s1
        for (char c : s1)
        {
            arr[c - 'a']++;
        }    

        for (int i = 0; i < n; i++)
        {
            // Decrement the count of character at this index
            arr[s2[i] - 'a']--;

            // IF the current index i - length of s1 is greater or equal to zero,
            // increment the count for character in s2 at index i - length of s2. 
            // This is to restore the count of a character that has decremented but does not appear in s1
            if (i - m >= 0) arr[s2[i - m] - 'a']++;

            // If arr contains all zero for character count,
            // permutation exists. Return true.
            if (allzero(arr)) return true;
        }
        return false;
    }
};

/*
Solution reference
Leetcode sample code
*/
