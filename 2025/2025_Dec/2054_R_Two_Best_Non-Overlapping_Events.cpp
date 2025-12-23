// 2025 Dec 23

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end());                             // sort by event's starting time
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));      // dp[i][j] = max sum at event[i] when j (0-2) events are chosen

        return findEvents(events, 0, 0, dp);
    }

    int findEvents(vector<vector<int>>& events, int idx, int cnt, vector<vector<int>>& dp)
    {
        int n = events.size();

        if (cnt == 2 || idx >= events.size()) return 0; // if 2 events are chosen already and the index is out of range, return 0.
        if (dp[idx][cnt] == -1)                         // compute the sum at event[idx] if the sum hasn't been computed
        {
            int end = events[idx][1];   // the end time for this event
            int lo = idx + 1;           // lo and hi are for binary search on the next non-overlapping event 
            int hi = n - 1;

            while (lo < hi)     // binary search on the next non-overlapping event
            {
                int mid = lo + ((hi - lo) >> 1);
                if (events[mid][0] > end) hi = mid;
                else lo = mid + 1;
            }

            // include: the sum when including the current event. 
            // current event's value + the next possible event's iteration or 0 if there are no more events that can be taken after
            int include = events[idx][2] + (lo < events.size() && events[lo][0] > end ? findEvents(events, lo, cnt + 1, dp) : 0);
            
            // exclude: skip the current event and compute the next event's iteration.
            int exclude = findEvents(events, idx + 1, cnt, dp);

            // save the greater sum: sum including the current event vs sum excluding the current event 
            dp[idx][cnt] = max(include, exclude);
        }
        return dp[idx][cnt];
    }
};

/*
solution reference
https://leetcode.com/problems/two-best-non-overlapping-events/editorial
*/
