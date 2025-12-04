// 2025 June 30
class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        map<int, int> m;    // count each number's frequency in nums
        for (int i : nums)
        {
            if (m.find(i) == m.end()) m.insert({i, 1});
            else m[i]++;
        }

        int ans = 0;
        int prev = m.begin()->first;

        // get sum of two adj keys that have difference of 1 and check if the sum of the two's frequency are larger than ans
        for (auto it = m.begin(); it != m.end(); ++it)  
        {
            if (it->first == prev) continue;
            if (it->first - prev == 1) ans = max(ans, m[prev] + it->second);
            prev = it->first;
        }
        return ans;
    }
};
