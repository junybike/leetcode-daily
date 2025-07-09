// 2025 July 9
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        int n = startTime.size();
        int t = 0;      // tracks total duration of meetings within a window
        int ans = 0;
            
        for (int i = 0; i < n; i++)
        {
            int L = (i <= k - 1) ? 0 : endTime[i - k];              // if window size is less than k, considers range from time 0. else, adjust to (i - k)th event's endtime
            int R = (i == n - 1) ? eventTime : startTime[i + 1];    // determine if the current event is the last event

            t += endTime[i] - startTime[i]; // tracks the total duration of meetings in this window
            ans = max(ans, R - L - t);      // update ans if R - L - t is larger than current largest

            if (i >= k - 1) t -= endTime[i - k + 1] - startTime[i - k + 1]; // update the total duration of meetings if window is size of k
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/editorial
*/
