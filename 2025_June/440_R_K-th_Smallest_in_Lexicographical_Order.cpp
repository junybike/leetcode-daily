// 2025 June 9

class Solution {
public:

    int countStep(int n, long pre1, long pre2)
    {
        int step = 0;
        while (pre1 <= n)
        {
            step += min((long)(n + 1), pre2) - pre1;
            pre1 *= 10;
            pre2 *= 10;
        }
        return step;
    }

    int findKthNumber(int n, int k) 
    {
        int cur = 1;
        k--;

        while (k > 0)
        {
            int step = countStep(n, cur, cur + 1); // find number of steps that can be skipped in this subtree at cur
            if (step <= k)  // if the step is less than k, it can skip 'step' amount of skips and move on to next subtree cur + 1
            {
                cur++;
                k -= step;
            }
            else // move to the next level in the subtree 1, 10, 100 etc
            {
                cur *= 10;
                k--;
            }
        }
        return cur;
    }
};

/*
solution
https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/editorial
*/
