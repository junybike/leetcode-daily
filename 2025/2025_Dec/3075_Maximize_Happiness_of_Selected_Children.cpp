// 2025 Dec 25

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        int round = 0;
        long long ans = 0;

        sort(happiness.begin(), happiness.end(), greater<>());  // sort happiness values descending order 
        for (int i : happiness)
        {
            if (i - round > 0) ans += (i - round);  // each round happiness goes down by 1. but no negatives. keep track of the round by 'round'
            round++;

            if (k - round == 0) break;  // if k happinesses are chosen, stop.
        }
        return ans;
    }
};
