// 2024 Oct 11

class Solution {
public:

    using info = array<int, 3>;     // (arrival, leaving, seat)
    using int2 = array<int, 2>;     // (leaving, seat)

    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int n = times.size();
        vector<info> schedule(n);

        // Assign arrival, leaving, seat to schedule vector and
        // sort them in increasing order of arrival time
        for (int i = 0; i < n; i++)
        {
            schedule[i] = {times[i][0], times[i][1], i};
        }
        sort(schedule.begin(), schedule.end());

        // Vacant seat vector
        // Initialize each seat a value 
        // where earliest time the seat has taken for the first time has lowest value [0, 1, ... n-1]
        vector<int> freeseat(n);
        iota(freeseat.begin(), freeseat.end(), 0);

        // turn freeseat vector into a heap (greatest to lowest)
        make_heap(freeseat.begin(), freeseat.end(), greater<int>{});
        // priority queue to keep track of used chairs
        priority_queue<int2, vector<int2>, greater<int2>> used;

        for (auto& t : schedule)
        {
            int arrival = t[0];
            int leaving = t[1];
            int index = t[2];
            int seat;

            // Replacing chair for current arrival with one who has left before its arrival
            while (!used.empty() && used.top()[0] <= arrival)
            {
                // Get the seat
                seat = used.top()[1];       

                // Store into the freeseat and maintain the order 
                freeseat.push_back(seat);   
                push_heap(freeseat.begin(), freeseat.end(), greater<int>{});

                // Remove the seat from 'used'
                used.pop();
            }

            // Assign person with free seat that has smallest value
            // and remove the seat assigned from freeseat
            pop_heap(freeseat.begin(), freeseat.end(), greater<int>{});
            seat = freeseat.back();
            freeseat.pop_back();
            
            // If the current index is the target, return the seat
            if (index == targetFriend) return seat;

            // Add current person's leaving time and its seat to the used queue
            used.push({leaving, seat});
        }
        return -1;
    }
};

/*
Solution reference
https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/solutions/5897612/sort-2-heaps-vs-1-heap-1-array-100ms-beats-99-66
*/
