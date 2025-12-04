// 2024 Dec 27

class SolutionTLE {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        vector<pair<int, int>> i_pair;
        vector<pair<int, int>> j_pair;
        int n = values.size();

        for (int i = 0; i < n; i++)
        {
            i_pair.push_back({values[i] + i, i});
            j_pair.push_back({values[i] - i, i});
        }

        sort(i_pair.begin(), i_pair.end(), greater<pair<int, int>>());    
        // sort(j_pair.begin(), j_pair.end()); 
        // for (auto i : i_pair) cout << i.first << " " << i.second << endl;
        // cout << endl;
        // for (auto i : j_pair) cout << i.first << " " << i.second << endl;

        int ans = 0;
        for (auto pair : i_pair)
        {
            for (int i = pair.second + 1; i < n; i++)
            {
                int score = pair.first + j_pair[i].first; 
                if (ans < score) ans = score;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int n = values.size();
        int dp = values[0];
        int ans = 0;

        if (n == 2) return values[0] + values[1] - 1;

        for (int i = 1; i < n; i++)
        {
            int score = values[i];
            if (ans < dp + score - i) ans = dp + score - i;
            if (dp < score + i) dp = score + i;
        }

        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/best-sightseeing-pair/solutions/6190941/recursive-iterative-dp-greedy-beats-100
*/
