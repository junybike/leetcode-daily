// 2025 Feb 25

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int count = 0;      // number of sub arrays with odd sum
        int prefixSum = 0;

        int oddCount = 0;   
        int evenCount = 1;  // prefixSum is 0 initially. 0 counts as even 

        for (int num : arr)
        {
            prefixSum += num;           // maintains 'prefixSum'

            if (prefixSum % 2 == 0)
            {
                count += oddCount;      // add the number of odd prefix sums count whenever current prefixSum is even.
                evenCount++;            // increment 'evenCount' as the prefixSum is now even
            }
            else
            {
                count += evenCount;     // add the number of even prefix sums count whenever currnet prefixSum is odd.
                oddCount++;             // increment 'oddCount' as the prefixSum is now odd
            }
            count %= int(1e9 + 7);
        }
        return count;
    }
};

// DP
class Solution2 {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int n = arr.size(); // number of values in 'arr'
        for (auto& i : arr) // edit values in 'arr' to 1 or 0 if it is odd or even respectively
        {
            i %= 2;
        }

        vector<int> evens(n);   // evens[i] represents number of subarrays with even sum ending at index i
        vector<int> odds(n);    // odds[i] represents number of subarrays with odd sum ending at index i

        // at the end of evens and odds, it just indicates if the last value in 'arr' is even or odd.
        if (arr[n - 1] == 0) evens[n - 1] = 1;
        else odds[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] == 1)    // current value in 'arr' at index i is odd 
            {
                odds[i] = (1 + evens[i + 1]) % int(1e9 + 7);    // update the 'odds' as current value is odd
                evens[i] = odds[i + 1];                         // updates 'evens' since case of odd + odd is possible and that leads to even   
            }
            else                // current value in 'arr' at index i is even
            {
                evens[i] = (1 + evens[i + 1]) % int(1e9 + 7);   // update the 'evens' as current value is even
                odds[i] = odds[i + 1];                          // updates 'odds' since even + odd is odd
            }
        }

        // sums up all odd subarrays
        int count = 0;
        for (auto i : odds)
        {
            count += i;
            count %= int(1e9 + 7);
        }
        return count;
    }
};
/*
solution reference
https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/editorial
*/
