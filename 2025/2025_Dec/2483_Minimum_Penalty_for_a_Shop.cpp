// 2025 Dec 26
class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int num_y = 0;  // total number of customers anytime
        for (char c : customers)
        {
            if (c == 'Y') num_y++;
        }    

        int time = 0;       // time at minimum penalty
        int cur = num_y;    // current penalty (same as the total num_y at time 0)
        int ans = num_y;    // to keep track of lowest penalty while traversing

        for (int i = 1; i <= customers.size(); i++)
        {
            if (customers[i - 1] == 'N') cur++;  // increase the penalty when encounters N
            else cur--; // decrease the penalty when encounters Y

            if (cur < ans) // update the time when a lower penalty is reached  
            {
                time = i;
                ans = cur;
            }
        }
        return time;
    }
};
