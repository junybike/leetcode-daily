// 2022 Oct 1

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        int size = arr.size();
        vector<int> freq(k, 0);

        // Checks the frequency of remainders when a value in arr is divided by k.
        // freq[i] -> holds number of values that has remainder of i when divided by k.
        for (int i = 0; i < size; i++)
        {
            freq[((arr[i] % k) + k) % k]++;
        }

        // Amount of frequency of 0 has to be even number, since in this case,
        // pairs of frequency with 0 has to be formed to make it divisible by k.
        if (freq[0] % 2 != 0) return false;

        // Amount of frequency i matching with amount of frequency k - i
        // indicates that there is a possible way to form a pair by using each values once. 
        for (int i = 1; i <= k / 2; i++)
        {
            if (freq[i] != freq[k - i]) return false;
        }

        return true;
    }
};

/*
solution reference
https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/solutions/5854226/can-you-pair-these-numbers-beats-100-explained-with-video-c-java-python-js-explained
*/
