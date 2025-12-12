// 2025 Dec 12
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) 
    {
        vector<int> cnt(numberOfUsers);                 // number of mentions for each users
        vector<int> next_online_time(numberOfUsers);    // stores the next online time when each users become offline

        // sort events in their timestamps
        sort(events.begin(), events.end(),
             [&](const vector<string>& lth, const vector<string>& rth) {
                 int lth_timestamp = stoi(lth[1]);
                 int rth_timestamp = stoi(rth[1]);
                 if (lth_timestamp != rth_timestamp) {
                     return lth_timestamp < rth_timestamp;
                 }
                 if (rth[0] == "OFFLINE") {
                     return false;
                 }
                 return true;
             });
        
        for (auto& e : events)
        {
            int cur = stoi(e[1]);   // current timestamp
            if (e[0] == "MESSAGE")
            {
                if (e[2] == "ALL")  // increments all users' mention cnt
                {
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        cnt[i]++;
                    }
                }
                else if (e[2] == "HERE")    // increments only online users' mention cnt
                {
                    for (int i = 0; i < numberOfUsers; i++)
                    {
                        if (next_online_time[i] <= cur) cnt[i]++;
                    }
                }
                else
                {
                    int idx = 0;
                    for (int i = 0; i < e[2].size(); i++)   // parse the message and find user ids and increment their mention cnt
                    {
                        if (isdigit(e[2][i])) idx = idx * 10 + (e[2][i] - '0');
                        if (i + 1 == e[2].size() || e[2][i + 1] == ' ')
                        {
                            cnt[idx]++;
                            idx = 0;
                        }
                    }
                }
            }
            else    // offline events. update the user's next online time
            {
                int idx = stoi(e[2]);
                next_online_time[idx] = cur + 60;
            }
        }
        return cnt;
    }
};

/*
solution reference
https://leetcode.com/problems/count-mentions-per-user/editorial
*/
