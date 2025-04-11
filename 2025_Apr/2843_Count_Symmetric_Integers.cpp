// 2025 Apr 11

class Solution {
public:

    int getsum(string& s)   // sum up individual digit in a string
    {
        int sum = 0;
        for (char c : s)
        {
            sum += c - '0';
        }
        return sum;
    }

    int countSymmetricIntegers(int low, int high) 
    {
        int cnt = 0;
        for (int i = low; i <= high; i++)
        {
            string num = to_string(i);      // converts current number to string
            int n = num.length();           // the string's length
            if (n % 2 != 0) continue;       // skip odd number sized length
            
            string x = num.substr(0, n/2);  // first half of string
            string y = num.substr(n/2);     // second half of string

            // check if the both halfs sum are the same
            if (getsum(x) == getsum(y)) cnt++;
        }    
        return cnt;
    }
};
