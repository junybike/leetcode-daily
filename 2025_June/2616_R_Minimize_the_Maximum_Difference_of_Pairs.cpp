// 2025 June 13
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) 
    {
        if (p == 0) return 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int L = 0;
        int R = nums[n - 1] - nums[0];

        while (L < R)
        {
            int M = L + (R - L) / 2;    // gets the middle value between L and R
            int pairs = 0;              // to count the pairs that are less or equal to M

            cout << L << " " << M << " " << R << endl;

            for (int i = 1; i < n; i++) // count the pairs that are less than or equal to M
            {
                if (M >= nums[i] - nums[i - 1]) 
                {
                    pairs++;
                    i++;
                }
            }
            if (pairs >= p) R = M;  // update R if there are more than or equal to p pairs
            else L = M + 1;         // update L if there are less than p pairs
        }
        return L;
    }
};
/*
solution reference
https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/6833834/binary-search-on-answer-with-images-example-walkthrough-c-python-java
*/
