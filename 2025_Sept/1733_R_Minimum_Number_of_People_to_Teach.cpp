// 2025 Sept 11
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) 
    {
        unordered_set<int> uset;    // to store friends who cannot communicate

        for (auto& i : friendships)
        {
            unordered_map<int, int> mp;
            bool com = false;

            // Check if a pair of friends can communicate each other
            // Lists languages friend 0 can speak
            for (int i : languages[i[0] - 1])
            {
                mp[i] = 1;
            }

            // Check if friend 1 can speak any language that friend 0 speaks
            for (int i : languages[i[1] - 1])
            {
                if (mp[i])
                {
                    com = true;
                    break;
                }
            }

            // Store the friends to uset
            if (!com)
            {
                uset.insert(i[0] - 1);
                uset.insert(i[1] - 1);
            }
        }    
        
        // Find the most common language that people who cant communicate knows
        int ans = 0;
        vector<int> cnt(n + 1, 0);
        for (auto& i : uset)
        {
            for (int i : languages[i])
            {
                cnt[i]++;
                ans = max(ans, cnt[i]);
            }
        }

        // Number of friends who cant communicate - most common language that people who cant communicate knows
        return uset.size() - ans;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-number-of-people-to-teach/editorial
*/
