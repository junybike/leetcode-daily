// 2024 Oct 8

class Solution {
public:
    int minSwaps(string s) 
    {
        int n = s.length();    // length of s 
        int open = 0;          // Keep track of opening bracket
        int close = 0;         // Keep track of closing bracket
        int ans = 0;           // Number of swaps

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[') open++;    // Increment count of opening bracket 
            else close++;               // Increment count of closing bracket

            // If, at any point, number of closing bracket is larger than opening bracket, the brackets are not balanced.
            // Assume that the bracket is swapped with an opening bracket and count of opening bracket is increased and closing bracket is decreased by one.
            // Increment count for swaps.
            if (close > open)            
            {
                open++;
                ans++;
                close--;
            }
        }
        return ans;
    }
};
