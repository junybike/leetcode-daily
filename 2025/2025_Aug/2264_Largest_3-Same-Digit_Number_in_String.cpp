// 2025 Aug 14
class Solution {
public:
    string largestGoodInteger(string num) 
    {
        int cnt = 1;
        int ans = -1;
        for (int i = 1; i < num.length(); i++)
        {
            if (num[i] == num[i - 1]) cnt++;
            else cnt = 1;
            if (cnt == 3) ans = max(ans, num[i] - '0');
        }    
        
        if (ans == -1) return "";
        return to_string(ans) + to_string(ans) + to_string(ans);
    }
};
