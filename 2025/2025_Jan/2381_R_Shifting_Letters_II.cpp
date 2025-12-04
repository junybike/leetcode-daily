// 2025 Jan 5

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.length();                         // The length of 's'
        vector<int> change = vector(n + 1, 0);      // To store the number of changes made for each characters in 's'

        for (auto& arr : shifts)
        {
            change[arr[0]] += (arr[2] == 1 ? 1 : -1);       // Add or subtract 1 from the starting index of range in 'arr'
            change[arr[1] + 1] -= (arr[2] == 1 ? 1 : -1);   // Add or subtract 1 from the ending index of range in 'arr'
        }


        // Calculate the prefix sum of the changes
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += change[i];
            change[i] = count;
        }

        // For each character, apply the changes according to the prefix sum values
        for (int i = 0; i < n; i++)
        {
            int shift = (change[i] % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        return s;
    }
};

/*
Solution reference
https://leetcode.com/problems/shifting-letters-ii/solutions/6231675/optimised-prefix-sum-detailed-expiation-beats-100
*/
