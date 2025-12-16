// 2025 Dec 16
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) 
    {
        vector<int> ptrs;   // stores each length of descent periods
        long long cnt = 1;  // keep track of the length of periods on each starting indexes
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - prices[i - 1] == -1) cnt++; // smooth descent periods condition
            else                                        // push cnt and reset it to 0 when condition isn't met 
            {
                ptrs.push_back(cnt);
                cnt = 1;
            }
        }
        ptrs.push_back(cnt);

        cnt = 0;
        for (long long i : ptrs)    // if a length is i, (i * (i + 1)) / 2 ways are possible 
        {
            cnt += (i * (i + 1)) / 2;
        }
        return cnt;
    }
};
