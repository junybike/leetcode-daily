// 2025 Dec 9
class Solution {
public:
    int specialTriplets(vector<int>& nums) 
    {
        int MOD = 1e9 + 7;
        int n = nums.size();
        
        unordered_map<int, int> cnt;        // stores frequency of each values present in nums
        unordered_map<int, int> partialcnt; // frequency of each values present in nums at a certain traversal position
        
        cnt.reserve(n * 2);
        partialcnt.reserve(n * 2);

        for (int i : nums)
        {
            cnt[i]++;
        }

        int ans = 0;
        for (int i : nums)
        {
            int target = i * 2;
            int cntL = partialcnt[target]; // i's total occurence so far 
            partialcnt[i]++;

            int cntR = cnt[target] - partialcnt[target];    // how many i's occurence left 
            ans = (ans + (cntL * 1LL * cntR % MOD)) % MOD;
        }
        return ans;
    }
};
/*
solution reference
*/
