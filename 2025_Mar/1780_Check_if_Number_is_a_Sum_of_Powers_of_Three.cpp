// 2025 March 4

class Solution {
public:
    bool checkPowersOfThree(int n) 
    {
        // array of powers of 3 within the range
        int pwr[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049,
                        177147, 531441, 1594323, 4782969, 14348907, 43046721};
        
        // Subtract n from largest powers of 3 to lowest
        for (int i = 16; i >= 0; i--)
        {
            if (n >= pwr[i]) n -= pwr[i];
            if (n == 0) return true;        // if n is reduced to 0, return true
        }
        return false;                       // otherwise, return false
    }
};
