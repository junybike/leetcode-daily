// 2024 Nov 9

class Solution {
public:
    long long minEnd(int n, int x) 
    {
        bitset<64> X(x);      // int 'x' in bitset
        bitset<64> N(n - 1);  // int 'n' - 1 in bitset
        bitset<64> ans;       // the minimum end value 

        // There are 56 bits  
        // Packing x & n - 1
        for (int i = 0, j = 0; i < 56; i++)
        {
            if (X[i]) ans[i] = 1;  // If the ith bit in X is 1, the ith bit of ans is 1.
            else ans[i] = N[j++];  // If not, use the same bit as N at jth bit. The j only increments when ith bit is not equal to ith of X.
        }
        return ans.to_ullong();    // Convert the bitset into long long.
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-array-end/solutions/6024899/bitset-with-o-56-time-beats-100
*/
