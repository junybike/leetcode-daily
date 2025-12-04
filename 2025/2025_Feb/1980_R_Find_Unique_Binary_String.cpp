// 2025 Feb 20

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        string ans = "";    // the binary string to return
        short i = 0;        // an index 

        for (string s : nums)
        {
            // Appends inverse of ith bit in the ith string
            if (s[i] == '1') ans += '0';     
            else ans += '1';
            i++;
        }
        return ans;
    }
};

/*
Solution reference
Leetcode discussion section
*/
