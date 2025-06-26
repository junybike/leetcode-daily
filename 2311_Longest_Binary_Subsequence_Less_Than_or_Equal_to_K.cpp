// 2025 June 27
class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int n = s.length();
        int cnt = 0;
        int cur = 0;
        int power = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0') cnt++; // if 0, increment cnt  
            else if (power < 32 && (cur + (1LL << power)) <= k) // if total value is less than k with the addition of 2-power, increment cnt
            {
                cur += 1LL << power;
                cnt++;
            }
            power++;
        }   
        return cnt;
    }
};
