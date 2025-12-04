// 2024 Dec 4

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) 
    {
        int index = 0;                  // An index to keep track of to traverse 'str2' while traversing 'str1'
        int str2_size = str2.length();  // The size of 'str2'

        for (char c : str1)
        {
            // If 'c' or incrementation of 'c' is same as str2[index], increment 'index' to check for the next character in 'str2'.
            // If the index reaches the str2_size, then subsequence exists in 'str1'. Return true.
            if (c == str2[index] || c + 1 == str2[index] || (c == 'z' && str2[index] == 'a')) index++;
            if (index == str2_size) return true;
        }

        // If index did not reach str2_size, no subsequence is found. Return false.
        return false;
    }
};
