// 2025 July 11

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        vector<long long> room_time(n, 0);          // store the meeting's endtime
        vector<int> room_cnt(n, 0);                 // store how many meetings have happened in the room
        sort(meetings.begin(), meetings.end());     
        
        for (auto& m : meetings)
        {
            int start = m[0];   // start time of current meeting
            int end = m[1];     // end time of current meeting
            
            long long minAvailable = LLONG_MAX; // earliest room that can be available
            int minRoom = 0;                    // the room number of above
            bool found = false;                 // indicates if vacant room is found

            for (int i = 0; i < n; i++)         // check each rooms
            {
                if (room_time[i] <= start)  // this room is available
                {
                    found = true;
                    room_cnt[i]++;
                    room_time[i] = end;
                    break;
                }
                if (minAvailable > room_time[i])    // update earliest room that can be available
                {
                    minAvailable = room_time[i];
                    minRoom = i;
                }
            }

            if (!found) // if no vacant room is found
            {
                room_time[minRoom] += end - start;
                room_cnt[minRoom]++;
            }
        }

        // find the room with most meetings held
        int maxCnt = 0;
        int maxRoom = 0;
        for (int i = 0; i < n; i++)
        {
            if (room_cnt[i] > maxCnt)
            {
                maxCnt = room_cnt[i];
                maxRoom = i;
            }
        }
        return maxRoom;
    }
};
/*
solution reference
https://leetcode.com/problems/meeting-rooms-iii/editorial
*/
