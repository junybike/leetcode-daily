// 2025 May 18
class Solution {
public:

    static constexpr int mod = 1000000007;

    int colorTheGrid(int m, int n) 
    {
        unordered_map<int, vector<int>> valid;
        int mask_end = pow(3, m);

        // find all masks (coloring schemes for a single row) that are valid 
        for (int mask = 0; mask < mask_end; mask++)
        {
            vector<int> col;
            int mm = mask;

            for (int i = 0; i < m; i++)
            {
                col.push_back(mm % 3);
                mm /= 3;
            }
            
            bool check = true;
            for (int i = 0; i < m - 1; i++)
            {
                if (col[i] == col[i + 1])
                {
                    check = false;
                    break;
                }
            }

            if (check) valid[mask] = move(col);
        }    

        // check all valid adj row pairs. (for m1, if m2 is valid, store m2 to m1's int vector)
        unordered_map<int, vector<int>> adj;
        for (const auto& [m1, c1] : valid)
        {
            for (const auto& [m2, c2] : valid)
            {
                bool check = true;
                for (int i = 0; i < m; i++)
                {
                    if (c1[i] == c2[i])
                    {
                        check = false;
                        break;
                    }
                }
                if (check) adj[m1].push_back(m2);
            }
        }

        // gather all valid counts 
        vector<int> f(mask_end);
        for (auto& [m, _] : valid)
        {
            f[m] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            vector<int> g(mask_end);
            for (auto& [m2, _] : valid)
            {
                for (int m1 : adj[m2])
                {
                    g[m2] += f[m1];
                    if (g[m2] >= mod) g[m2] -= mod;
                }
            }
            f = move(g);
        }

        // add all valid counts
        int ans = 0;
        for (int n : f)
        {
            ans += n;
            if (ans >= mod) ans -= mod;
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/painting-a-grid-with-three-different-colors/editorial
*/
