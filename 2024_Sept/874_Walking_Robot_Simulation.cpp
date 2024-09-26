// 2024 Sept 4

class Solution 
{
public:
 
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        int x = 0; 
        int y = 0;
        int neg = 1;

        int direction = 0; // 0 = N, 1 = E, 2 = S, 3 = W
        int max = 0;

        // positive: heading N and/or E
        // negative: heading S and/or W

        for (int i = 0; i < commands.size(); i++)
        {
            if (direction > 1) neg = -1;
            if (direction < 2) neg = 1;

            switch (commands[i])
            {
                case -1:  // Case: turning right
                    
                    direction = (direction + 1) % 4;
                    break;

                case -2: // Case: turning left

                    direction--;
                    if (direction == -1) direction = 3;
                    break;

                default:

                    int x_prev = x;
                    int y_prev = y;

                    if (direction == 0 || direction == 2) y += (commands[i] * neg);
                    else x += (commands[i] * neg);

                    // The robot taking steps control and detect obstacles
                    for (int k = 0; k < obstacles.size(); k++)
                    {
                        if (direction == 0 && x == obstacles[k][0] && y >= obstacles[k][1] && y_prev < obstacles[k][1])
                        {
                            y = obstacles[k][1] - 1;
                        }
                        else if (direction == 1 && y == obstacles[k][1] && x >= obstacles[k][0] && x_prev < obstacles[k][0])
                        {
                            x = obstacles[k][0] - 1;
                        }
                        else if (direction == 2 && x == obstacles[k][0] && y <= obstacles[k][1] && y_prev > obstacles[k][1])
                        {
                            y = obstacles[k][1] + 1;
                        }
                        else if (direction == 3 && y == obstacles[k][1] && x <= obstacles[k][0] && x_prev > obstacles[k][0])
                        {
                            x = obstacles[k][0] + 1;
                        }
                    }
                    break;
            }
            if (x * x + y * y > max) max = x * x + y * y;
        }
        return max;
    }
};
