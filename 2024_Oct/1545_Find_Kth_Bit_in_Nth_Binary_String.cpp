// 2024 Oct 19

class Solution {
public:
    char findKthBit(int n, int k) 
    {
        string sbit = "0"; // The S at ith iteration (currently i = 0)
        
        for (int i = 0; i < n; i++)
        {
            string temp = invert(sbit);         // Inverted 'sbit' string 
            reverse(temp.begin(), temp.end());  // Reverse the inverted string
            sbit = sbit + "1" + temp;           // Update the 'sbit'
        }   
        return sbit[k - 1];  // Get the kth bit
    }


    // Change all 1 to 0 and 0 to 1 in string 's'
    // Does not modify original string 's'. Returns new string with inverted bits of string s.
    string invert(string& s)
    {
        string ret = "";
        for (char& c : s)
        {
            if (c == '0') ret += '1';
            else ret += '0';
        }
        return ret;
    }
};
