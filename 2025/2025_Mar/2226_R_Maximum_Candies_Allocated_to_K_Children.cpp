// 2025 Mar 14

class Solution {
public:

    bool give_candy(vector<int>& candies, long long k, int n)
    {
        // Checks if there are enough piles that can distribute 'n' cookies for 'k' childs 
        long long maxchilds = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            maxchilds += candies[i] / n;
        }        
        return maxchilds >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) 
    {
        // Finds the max amount of candy in 'candies'
        int maxcandy = 0;
        for (int i : candies)
        {
            if (maxcandy < i) maxcandy = i;
        }

        int L = 0;
        int R = maxcandy;

        // Check the max amount of candies can be distributed with binary search
        while (L < R)
        {
            int M = (L + R + 1) / 2;
            if (give_candy(candies, k, M)) L = M;
            else R = M - 1;
        }
        return L;
    }
};
/*
solution reference
https://leetcode.com/problems/maximum-candies-allocated-to-k-children/editorial
*/
