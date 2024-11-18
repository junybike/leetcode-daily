// 2024 Nov 18

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();      // the size of vector 'code'
        vector<int> ans(n, 0);    // the vector containing decrypted code. 
        if (k == 0) return ans;   // If k is 0, the decrypted code is all 0

        // For positive k greater than 0
        if (k > 0)
        {
            for (int i = 0; i < n; i++)
            {
                // Calculate the sum of right next k values from the value at index i in 'code' vector 
                // to calculate decrypted code for ith code.
                int temp = 0;
                for (int j = 0; j < k; j++)
                {
                    temp += code[(i + j + 1) % n];
                }
                ans[i] = temp;
            }
        }
        // For negative k less than 0
        else
        {
            for (int i = 0; i < n; i++)
            {
                // Calculate the sum of left next k values from the value at index i in 'code' vector
                // to calculate decrypted code for ith code.
                int temp = 0;
                for (int j = 0; j > k; j--)
                {
                    temp += code[(n + i + j - 1) % n];
                }
                ans[i] = temp;
            }
        }
        return ans;    
    }
};

// Better solution O(n + k)

class SolutionR {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();        // The size of vector 'code'
        vector<int> ans(n, 0);      // The decrypted code to return
        if (k == 0) return ans;     // If k is 0, the code is all 0. Return 'ans'.

        // Case when k is greater than 0
        if (k > 0)
        {
            // Get the sum for 'code' at first index. 
            int sum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            ans[0] = sum;

             // Perform sliding window
            for (int L = 1, R = k + 1; L < n; R++, L++)
            {
                // For the next n - 1 decrypted code, assign the
                // previous code + right next value of 'code' - the first value of 'code' added for the previous decrypted code    
                sum += code[R % n] - code[L];
                ans[L] = sum;
            }
        }

        // Case when k is less than 0
        else
        {
            k = -k;  // Set k positive

            // Get the sum for 'code' at first index
            int sum = accumulate(code.end()-k , code.end(), 0);
            ans[0] = sum;

            // Perform sliding window
            for (int R = 0, L = n - k; R < n - 1; R++, L++)
            {
                // For the next n - 1 decrypted code, assign the
                // previous decrypted code + left next value of 'code' - the first value of 'code' added for the previous decrypted code 
                sum += code[R] - code[L % n];
                ans[R + 1] = sum;
            }
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/defuse-the-bomb/solutions/6056351/sliding-window-for-k-0-or-k-0-beats-100
*/
