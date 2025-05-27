// 2025 May 27

class Solution {
public:
    int differenceOfSums(int n, int m) 
    {
        int num1 = 0;   // sum of all non divisible values 1 to n 
        int num2 = 0;   // sum of all divisible values 1 to n

        for (int i = 1; i <= n; i++)
        {
            if (i % m) num1 += i;
            else num2 += i;
        }    
        return num1 - num2;
    }
};
