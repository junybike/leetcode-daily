// 2025 June 20
class Solution {
public:
    int maxDistance(string s, int k) 
    {
        int x = 0;
        int y = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            switch (s[i])
            {
                case 'N':
                    y++;
                    break;
                case 'S':
                    y--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
            }

            // k * 2: each direction change increases 2+ distance 
            ans = max(ans, min(abs(x) + abs(y) + k * 2, i + 1));
        }    
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/editorial
*/
