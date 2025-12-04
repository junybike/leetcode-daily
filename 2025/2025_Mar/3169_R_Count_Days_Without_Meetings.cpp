// 2025 Mar 24

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end()); // sorts 'meetings' based on starting times
        int cnt = 0;                            // number of free days
        int prevEnd = 0;                        // previous ending time

        for (auto& arr : meetings)
        {
            int start = arr[0];     // start time of meeting
            int end = arr[1];       // end time of meeting
            
            if (start > prevEnd + 1) cnt += (start - prevEnd - 1);  // count the number of non-overlapping meetings and sum up to 'cnt'
            if (prevEnd < end) prevEnd = end;   // update the previous meeting end time if it is later than the previous end time                        
        }
        return cnt + (days - prevEnd);          // return the 'cnt' including the days after last day of meeting
    }
};
/*
solution reference
https://leetcode.com/problems/count-days-without-meetings/editorial
*/
