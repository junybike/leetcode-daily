// 2024 Oct 8

class Solution {
public:
    int minSwaps(string s) 
    {
        int n = s.length();
        int open = 0;
        int close = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '[') open++;
            else close++;

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
