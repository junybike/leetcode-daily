// 2025 June 9
class Solution {
public:
    vector<int> lexicalOrder(int n) 
    {
        vector<int> ans;
        int cur = 1;

        for (int i = 0; i < n; i++)
        {
            ans.push_back(cur);
            if (cur * 10 <= n)  // for patterns like 1, 10, 100, 1000
            {
                cur = cur * 10;
            }
            else
            {
                while (cur >= n || cur % 10 == 9) // to go back and continue from the numbers skipped from the above pattern
                {
                    cur = cur / 10;
                }
                cur++;
            }
        }
        return ans;
    }
};
