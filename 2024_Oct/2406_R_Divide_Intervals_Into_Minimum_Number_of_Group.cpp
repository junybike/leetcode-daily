// 2024 Oct 12

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) 
    {
        vector<int> start_time;     // to store start times from each interval in sorted order
        vector<int> end_time;       // to store end times from each interval in sorted order

        // push all start and end times into corresponding vector
        // and sort both vectors in ascending order
        for (auto& t : intervals)
        {
            start_time.push_back(t[0]);
            end_time.push_back(t[1]);
        }    
        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());

        int ans = 0;        // keep tracks of group numbers
        int index = 0;      // keep tracks of an index for end time vector

        for (int i : start_time)
        {
            // If the start time is later than the earliest endtime,
            // no need to add new group. Increment index for endtime
            // to compare the next earliest time with the next start time.
            // Else, new group needs to be made. Increment the ans.
            if (i > end_time[index]) index++;   
            else ans++;
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/solutions/5901109/beats-100-tc-sc-simple-and-easy-to-understand-python-cpp-java
*/
