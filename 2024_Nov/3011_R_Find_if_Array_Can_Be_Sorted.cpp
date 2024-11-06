// 2024 Nov 6

class Solution {
public:

    using intpair = pair<int, int>;

    bool canSortArray(vector<int>& nums) 
    {
        intpair prev = {INT_MIN, INT_MIN};  // contains min, max values right before the current iteration
        intpair current;                    // contains min, max values at current iteration
        int prevbit = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i];                         // current number in 'nums'
            int bitcount = __builtin_popcount(temp);    // number of 1 bit in 'temp'

            // If the 'prevbit' is not equal to 'bitcount' and the 
            // number appearing first is larger than the next appearing number, return false.
            //      (cannot switch values with different set bits)
            // If the number appearing first is not larger than the next appearing number,
            // update the 'prev' pair to the 'current' pair, update the 'current' pair to hold 'temp',
            // and update the 'prevbit' 
            //      (case where adjacent numbers have different set bits but they are in order)

            // Else, update 'current' pair by maintaining the min, max pair by taking consideration of 'temp'

            if (prevbit != bitcount)
            {
                if (current.first < prev.second) return false;
                prev = current;
                current = {temp, temp};
                prevbit = bitcount;
            }
            else
            {
                current.first = min(current.first, temp);
                current.second = max(current.second, temp);
            }
        }

        // Lastly, compare the last two numbers in the 'nums'
        return current.first >= prev.second;
    }
};

/*
solution reference
https://leetcode.com/problems/find-if-array-can-be-sorted/solutions/6013334/find-min-max-for-mutable-subarrays-in-o-n-0ms-beats-100
*/
