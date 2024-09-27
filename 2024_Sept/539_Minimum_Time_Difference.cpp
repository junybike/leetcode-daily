// 2024 Sept 16

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        int size = timePoints.size();
        int ans = 1440;  // Largest minutes possible 
        
        for (int i = 0; i < size; i++)
        {
            int a_hour = (int(timePoints[i][0]) - '0') * 10 + int(timePoints[i][1]) - '0';  // Amount of an hour of time point to compare to...
            int a_min = (int(timePoints[i][3]) - '0') * 10 + int(timePoints[i][4]) - '0';    // Amount of minutes of time point to compare to...
            
            for (int j = i + 1; j < size; j++)
            {
                if (ans == 0) return 0;
                int b_hour = (int(timePoints[j][0]) - '0') * 10 + int(timePoints[j][1]) - '0';  // the amount of an hour of time point.
                int b_min = (int(timePoints[j][3]) - '0') * 10 + int(timePoints[j][4]) - '0';  // the amount of minutes of time point.

                if (a_hour == b_hour)  // Case where the two time points have the same hour.
                {
                    int diff_min = max(a_min, b_min) - min(a_min, b_min);  // The minute difference of the two time point
                    if (diff_min < ans) ans = diff_min;  // Replace if the difference is lower than the current lowest difference
                }
                else
                {
                    // Consider two ways to get the difference between two time points
                    // a - b
                    int diff_hour1 = (a_hour - b_hour + 24) % 24;   // Prevents the hour to be negative
                    int diff_min1 = (a_min - b_min + 60) % 60;      // Prevents the minute to be negative
                    if (a_min - b_min < 0) diff_hour1--;            // If the minute difference is negative, decrease the hour by one
                    int diff1 = diff_hour1 * 60 + diff_min1;        // a - b
                  
                    // b - a
                    int diff_hour2 = (b_hour - a_hour + 24) % 24;   
                    int diff_min2 = (b_min - a_min + 60) % 60;
                    if (b_min - a_min < 0) diff_hour2--;
                    int diff2 = diff_hour2 * 60 + diff_min2;

                    // Compare the lowest of the two results with the current lowest difference.
                    // Replace if one of the results is lower than the lowest difference.
                    if (min(diff1, diff2) < ans) ans = min(diff1, diff2);
                }
            }
        }        

        return ans;
    }
};
