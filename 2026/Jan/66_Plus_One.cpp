// 2026 Jan 1
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int remainder = 0;      // indicates remainder if added on 9
        int n = digits.size();  
        
        digits[n - 1] = (digits[n - 1] + 1) % 10;   // adds on the first digit
        if (digits[n - 1] == 0) remainder = 1;      // case of adding 1 on 9

        for (int i = n - 2; i >= 0; i--)
        {
            digits[i] = (digits[i] + remainder) % 10;   
            if (digits[i] != 0) remainder = 0;          // if a digit isn't 0 anymore, no more remainder is produced
        }
        if (remainder) digits.insert(digits.begin(), 1);    // if there is a remainder at the end, extra one is added at the front.

        return digits;
    }
};
