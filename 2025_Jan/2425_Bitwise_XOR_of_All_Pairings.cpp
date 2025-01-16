// 2025 Jan 16

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();  // size of nums1
        int n2 = nums2.size();  // size of nums2
        int ans = 0;            // XOR of all integers 

        // If 'n1' is an odd number, the final XORed values will be equivalent to XORing all values in 'nums2' once.
        if (n1 % 2 != 0)
        {
            for (int& i : nums2)
            {
                if (ans == 0) ans = i;
                else ans = ans ^ i;
            }
        }

        // If 'n2' is an odd number, the final XORed values will be equivalent to XORing all values in 'nums1' once.
        if (n2 % 2 != 0)
        {
            for (int& i : nums1)
            {
                if (ans == 0) ans = i;
                else ans = ans ^ i;
            }
        }

        // If n1 or n2 size was even, it would be similar to XORing values twice, which is equivalent to no change.

        return ans;
    }
};
