// 2025 Dec 7
class Solution {
public:
    int countOdds(int low, int high) 
    {
        // there are (high - low) odd numbers in between low and high.
        // add an extra one if low or high is an odd number
        return (high - low) / 2 + (low % 2 || high % 2);
    }
};
