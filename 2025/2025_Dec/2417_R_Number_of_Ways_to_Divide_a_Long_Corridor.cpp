// 2025 Dec 14
class Solution {
public:

    const int MOD = 1e9 + 7;

    int numberOfWays(string corridor) 
    {
        long count = 1;     // number of ways
        int seat = 0;       // number of seats in current section
        int prevSeat = -1;  // index of last S in the previous section

        for (int i = 0; i < corridor.length(); i++)
        {
            if (corridor[i] == 'S') 
            {
                seat++;
                if (seat == 2)  // the last S in this section
                {
                    prevSeat = i;
                    seat = 0;
                }
                else if (seat == 1 && prevSeat != -1)   // the first S in this section
                {
                    count *= (i - prevSeat);
                    count %= MOD;
                }   
            }
        }
        if (seat == 1 || prevSeat == -1) return 0;  // odd seats and zero seat are not possible
        return (int)count;
    }
};
/*
solution reference
https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/editorial
*/
