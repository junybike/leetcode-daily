// 2025 July 18
class Solution {
public:
    long long minimumDifference(vector<int>& nums) 
    {
        int n = nums.size() / 3;
        long long sum = 0;
        vector<long long> p1(n + 1);

        priority_queue<int> ql;         
        for (int i = 0; i < n; i++)     // goes from the first n values from n
        {
            sum += nums[i];
            ql.push(nums[i]);
        }

        p1[0] = sum;                    // the sum of first n values
        for (int i = n; i < n * 2; i++) // goes from the first n values to second n values
        {
            sum += nums[i];
            ql.push(nums[i]);
            sum -= ql.top();        // remove the greatest value stored in ql
            ql.pop();
            p1[i - (n - 1)] = sum;
        }

        long long p2 = 0;           // stores last values to second n values 
        priority_queue<int, vector<int>, greater<int>> qr;
        for (int i = n * 3 - 1; i >= n * 2; i--)
        {
            p2 += nums[i];
            qr.push(nums[i]);
        }

        long long ans = p1[n] - p2;
        for (int i = n * 2 - 1; i >= n; i--)    // from the second n to first n values
        {
            p2 += nums[i];
            qr.push(nums[i]);
            p2 -= qr.top();                     // deletes n largest values in qr
            qr.pop();
            ans = min(ans, p1[i - n] - p2);
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/editorial
*/
