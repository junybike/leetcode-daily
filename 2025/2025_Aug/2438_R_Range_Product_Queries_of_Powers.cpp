// 2025 Aug 11
class Solution {
public:

    static constexpr int mod = 1000000007;

    vector<int> productQueries(int n, vector<vector<int>>& queries) 
    {
        vector<int> bins;   // to store values of power of 2
        int cnt = 1;
        
        while (n)   // calculate and store values of power of 2
        {
            if (n % 2 == 1) bins.push_back(cnt);
            cout << cnt << endl;
            n /= 2;
            cnt *= 2;
        }    

        vector<int> ans;
        for (auto& query : queries)
        {
            int cur = 1;
            for (int i = query[0]; i <= query[1]; i++)  // calculate product queries of power
            {
                cur = static_cast<long long>(cur) * bins[i] % mod;
            }
            ans.push_back(cur);
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/range-product-queries-of-powers/editorial
*/
