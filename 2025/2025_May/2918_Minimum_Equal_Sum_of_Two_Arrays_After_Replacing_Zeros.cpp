// 2025 May 10

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long long sumA = 0; long long sumB = 0;     // Current sum from both vectors
        long long zeroA = 0; long long zeroB = 0;   // Number of zeros in both vecotrs

        // Find sumA, sumB, zeroA, zeroB
        for (int& i : nums1)    
        {
            if (i == 0) zeroA++;
            else sumA += i;
        }    
        for (int& i : nums2)
        {
            if (i == 0) zeroB++;
            else sumB += i;
        }

        // Not possible cases
        if (sumA + zeroA > sumB && zeroB == 0) return -1;
        if (sumB + zeroB > sumA && zeroA == 0) return -1;

        // return the largest sum + its number of zeros. 
        // lower values cannot make it since only addition of positive values are allowed 
        return max(sumA + zeroA, sumB + zeroB);
    }
};
