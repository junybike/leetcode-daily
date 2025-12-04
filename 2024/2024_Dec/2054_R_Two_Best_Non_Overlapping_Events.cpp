// 2024 Dec 8

class Solution {
public:

    using info = tuple<int, bool, int>;

    int maxTwoEvents(vector<vector<int>>& events) 
    {
        int n = events.size();      // size of 'events'
        vector<info> time(2 * n);   // new time 'vector' contains start and end for each event in 'events' 

        for (int i = 0; i < n; i++)
        {
            int s = events[i][0];   // The starting time for this event
            int e = events[i][1];   // The end time for this event
            int v = events[i][2];   // The value of this event

            time[2 * i] = {s, 0, v};        // Store the start time this event in 'time' (0 indicates this value is not for an ending)
            time[2 * i + 1] = {e, 1, v};    // Store the end time for this event in 'time'(1 indicates this value is for an ending)
        }   
        sort(time.begin(), time.end());     // Sort base on the time.

        int ans = 0;    // best sum of 2 values to return
        int max_v = 0;  // a max value to keep track of

        for (auto& [t, isEnd, v] : time)
        {
            if (isEnd) max_v = max(max_v, v);   // If this is an end time for an event, check if this event has higher value than 'max_v'. Update if larger.
            else ans = max(ans, max_v + v);     // If a sum of two event is greater than highest sum so far, update the 'ans'.
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/two-best-non-overlapping-events/solutions/6124257/sort-greedy-vs-dp-binary-search-22ms-beats-100
*/
