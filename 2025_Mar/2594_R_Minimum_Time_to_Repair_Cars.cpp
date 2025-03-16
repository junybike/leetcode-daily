class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) 
    {
        long long L = 1;                                // mininum boundary for time
        long long R = 1LL * cars * cars * ranks[0];     // maximum boundary for time

        // binary search to find the minimum time possible to fix all cars
        while (L < R)
        {
            long long M = (L + R) / 2;  // middle value of L and R
            long long cnt = 0;          // number of cars can be fixed

            for (int i : ranks)
            {
                // increment 'cnt' by how many cars can each mechanics can fix in 'M' time
                cnt += sqrt(1 * M / i); 
            }

            // updating the boundary for search
            if (cnt < cars) L = M + 1;  
            else R = M;
        }
        return L;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-time-to-repair-cars/editorial
*/
