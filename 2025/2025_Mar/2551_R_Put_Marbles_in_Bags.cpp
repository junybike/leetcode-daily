// 2025 Mar 31

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) 
    {
        int n = weights.size();
        vector<int> pairWeights(n - 1, 0);  // sum up adjacent values and store (pair)

        for (int i = 0; i < n - 1; i++)
        {
            pairWeights[i] += weights[i] + weights[i + 1];
        }    

        sort(pairWeights.begin(), pairWeights.end());   // sort the pairs
        long long ans = 0;
        for (int i = 0; i < k - 1; i++) // sum up diff between largest k - 1 values and smallest k - 1 values
        {
            ans += pairWeights[n - 2 - i] - pairWeights[i];
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/put-marbles-in-bags/editorial
*/
