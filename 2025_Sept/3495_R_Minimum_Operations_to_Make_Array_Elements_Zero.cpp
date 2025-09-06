// 2025 Sept 6
class Solution {
public:

    long long get(int num)
    {
        int i = 1;
        int base = 1;
        long long cnt = 0;

        while (base <= num)
        {
            // to determine the number of operations, need to know the binary number of length  
            cnt += (long long)1 * (i + 1) / 2 * (min(base * 2 - 1, num) - base + 1);
            i++;
            base *= 2;
        }
        return cnt;
    }

    long long minOperations(vector<vector<int>>& queries) 
    {
        long long ans = 0;
        for (auto& q : queries)
        {
            ans += (get(q[1]) - get(q[0] - 1) + 1) / 2;
        }    
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/editorial
*/
