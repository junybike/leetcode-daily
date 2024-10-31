// 2024 Oct 31

class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) 
    {
        // Sizes of factory and robot
        int n = factory.size();
        int m = robot.size();

        // Sort robot and factory vector for optimal assignment
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());    

        // DP table to store minimum distances for robots to factories
        // dp[i][j]: i for robot and j for factory
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1))
        
        // Set distance to INF if there are no available factories
        for (int i = 0; i < m; i++)
        {
            dp[i][n] = LLONG_MAX;
        }

        // Processing factories from right to left
        for (int j = n - 1; j >= 0; j--)
        {
            long long dist = 0;             // Cumulative distance from current factory to robots
            deque<pair<int, long long>> q;  // To store pairs of robot index and its minimum distance to a factory
            q.push_back({m, 0});            // Base case sets all distance to 0

            // Processing robots from right to left
            for (int i = m - 1; i >= 0; i--)
            {
                // Adding distance from current robot to current factory
                dist += abs(robot[i] - factory[j][0]);
                
                // Remove ones that exceeding factory capacity
                while (!q.empty() && q.front().first > i + factory[j][1]) q.pop_front();
                // To maintain monotonic property of 'q'
                while (!q.empty() && q.back().second >= dp[i][j + 1] - dist) q.pop_back();

                // Add the current state to 'q'
                q.push_back({i, dp[i][j + 1] - dist});
                // Calculating minimum distance for current state
                dq[i][j] = q.front().second + dist;
            }
        }
        return dp[0][0]; // The minimum total distance starting from first robot and first factory
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-total-distance-traveled/solutions/5988185/beats-100-working-31-10-2024-explained-step-by-step-happy-halloween-night-shift
*/
