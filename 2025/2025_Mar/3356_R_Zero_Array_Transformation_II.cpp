// 2025 Mar 13

// Binary search
class Solution {
public:

    bool zeroarray(vector<int>& nums, vector<vector<int>>& queries, int k)
    {
        int n = nums.size();
        int sum = 0;

        // contains the least value the each value at each index in nums can reach after queries subtraction
        vector<int> diff_arr(n + 1);    

        for (int i = 0; i < k; i++)
        {
            int L = queries[i][0];
            int R = queries[i][1];
            int val = queries[i][2];

            diff_arr[L] += val;         // add the value to the start of range
            diff_arr[R + 1] -= val;     // subtract the value to the end of range
        }
        
        for (int i = 0; i < n; i++)
        {
            // if the sum at an index is lower than nums[index], zero array cannot be formed
            sum += diff_arr[i];         
            if (sum < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        int L = 0;
        int R = queries.size();

        // Finds the minimum amount of queries to subtract to make zero array with binary search
        if (!zeroarray(nums, queries, R)) return -1;
        while (L <= R)
        {
            int M = L + (R - L) / 2;
            if (zeroarray(nums, queries, M)) R = M - 1;
            else L = M + 1;
        }

        return L;
    }
};

// Line sweep
class Solution2 {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) 
    {
        int n = nums.size();
        int sum = 0;
        int k = 0;

        vector<int> diff_arr(n + 1);
        for (int i = 0; i < n; i++)
        {
            while (sum + diff_arr[i] < nums[i]) // more operations needed to current index
            {
                k++;
                if (k > queries.size()) return -1;  // all queries are processed

                int L = queries[k - 1][0];
                int R = queries[k - 1][1];
                int val = queries[k - 1][2];

                if (R >= i)
                {
                    diff_arr[max(L, i)] += val; // updates start of range
                    diff_arr[R + 1] -= val;     // updates end of range
                }
            }
            sum += diff_arr[i];
        }    
        return k;
    }
};

/*
solution reference
https://leetcode.com/problems/zero-array-transformation-ii/editorial
*/
