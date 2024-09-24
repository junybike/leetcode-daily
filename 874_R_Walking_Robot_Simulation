// 2024 Sept 4
class Solution 
{
public:

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        // N, E, S, W
        vector<vector<int>> d_type = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        int x = 0;
        int y = 0;
        int ans = 0;

        // For each x, find corresponding y values that are (x, y) pairs (obstacles)
        unordered_map<int, unordered_set<int>> obs;
        for (int i = 0; i < obstacles.size(); i++)
        {
            obs[obstacles[i][0]].insert(obstacles[i][1]);
        }

        // Execute commands
        for (int i : commands)
        {
            switch (i)
            {
                case -2:    // Turn left

                    direction = (direction + 3) % 4;
                    break;
                
                case -1:    // Turn right

                    direction = (direction + 1) % 4;
                    break;

                default:    // Take steps 

                    for (int j = 0; j < i; j++)
                    {
                        // If the obstacle pair map at current x value is not empty 
                        // and there is a matching obstacle on the next step, stop. 
                        if (!obs[x + d_type[direction][0]].empty() && 
                            obs[x + d_type[direction][0]].contains(y + d_type[direction][1]))
                            break;
                        
                        // Else, take a step.
                        x += d_type[direction][0];
                        y += d_type[direction][1];
                    }

                    // Update the max euclidean distance.
                    ans = max(ans, x * x + y * y);
                    break;
            }
        }
        return ans;
    }
};

/*
The answer reference:
https://leetcode.com/problems/walking-robot-simulation/solutions/5734512/simple-easy-solution-c
/*
