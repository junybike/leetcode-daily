// 2024 Sept 3

class Solution 
{
public:

    int getLucky(string s, int k) 
    {
        int ans = 0;
        int n = 96;  // offset
        string ss = s;

        for (int i = 0; i < k; i++)
        {
            ans = 0;
            for (int i = 0; i < ss.size(); i++)
            {
                // Convert each characters in ss into numerical value 
                // a -> 1, b -> 2, ... z -> 26

                // Case of numerical value greater than 10: Split the two number
                if (int(ss[i]) - n > 9)
                {
                    ans += (int(ss[i]) - n) / 10;
                    ans += (int(ss[i]) - n) % 10;
                }
                // Case of numerical value less than 10. Add the number directly
                else
                {
                    ans += int(ss[i]) - n;
                }
            }
            ss = to_string(ans);
            n = 48;
        }
        return ans;
    }
};
