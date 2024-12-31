// 2024 Dec 31 

class Solution {
public:

    bitset<366> need = 0;  // To store the day that are contained in 'days'
    int dp[366];           // To store the minimum cost for this day

    int rec(int d, int d0, vector<int>& costs)
    {
        if (d < d0) return 0;                      
        if (!need[d]) return rec(d - 1, d0, costs); // If this day is not part of the 'days', skip this day.
        if (dp[d] != -1) return dp[d];              // Case where 'd' day has computed already

        // Out of 3 choices of tickets, choose the lowest cost that can cover upto day 'd'
        return dp[d] = min({costs[0] + rec(d - 1, d0, costs), costs[1] + rec(d - 7, d0, costs), costs[2] + rec(d - 30, d0, costs)}); 
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        memset(dp, -1, sizeof(dp)); // Set all values in 'dp' as -1.

        // Initializing the 'need' vector.
        for (int i : days)
        {
            need[i] = 1;
        }
        return rec(days.back(), days[0], costs);
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-cost-for-tickets/solutions/6207118/3-different-recursive-dp-beats-100
*/
