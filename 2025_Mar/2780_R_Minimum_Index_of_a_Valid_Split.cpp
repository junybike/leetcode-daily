// 2025 Mar 27

class Solution {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, int> mapL;
        unordered_map<int, int> mapR;

        for (auto& i : nums)    // record the frequency of values in 'nums'
        {
            mapR[i]++;
        }    
        for (int i = 0; i < n; i++) 
        {
            int num = nums[i];  // for each value, remove the frequency recorded in 'mapR' and add to the 'mapL'
            mapR[num]--;
            mapL[num]++;

            // Check if the split is valid
            // If the frequency of current value * 2 is larger than the number of values in the splited array
            if (mapL[num] * 2 > i + 1 && mapR[num] * 2 > n - i - 1) return i;
        }
        return -1;
    }
};

// Boyer-Moore Majority Voting Algorithm
class Solution2 {
public:
    int minimumIndex(vector<int>& nums) 
    {
        int n = nums.size();
        int val = nums[0];
        int cnt = 0;

        for (int i : nums)
        {
            if (i == val) cnt++;
            else cnt--;
            if (cnt == 0) 
            {
                val = i;
                cnt = 1;
            }
        }

        int valcnt = 0;
        cnt = 0;
        for (int i : nums)
        {
            if (i == val) valcnt++;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val) cnt++;
            if (cnt * 2 > i + 1 && (valcnt - cnt) * 2 > n - i - 1) return i;
        }
        return -1;
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-index-of-a-valid-split/editorial
*/
