// 2024 Nov 26

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<int> degree(n, 0);   // To stores the degree for each team
        vector<int> deg0;           // To store the teams with degree 0.

        // Identify all teams that are weaker than some team.
        // For those team, increase their degree in 'degree' vector
        for (auto& arr : edges)
        {
            degree[arr[1]]++;
        }

        // Goes through the 'degree' vector and find any team with degree 0
        // and store into the 'deg0' vector.
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0) deg0.push_back(i);
        }

        // If there are multiple teams with degree 0, no unique team exists. Return -1.
        // Otherwise, return the unique team.
        if (deg0.size() != 1) return -1;
        return deg0[0];
    }
};

/*
solution reference
https://leetcode.com/problems/find-champion-ii/solutions/6083441/count-deg-find-deg-0-beats-100
*/
