// 2025 Jan 14

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        short n = A.size();         // The size of vector A and B
        short freq[51] = {0};       // Records the frequency of values in A and B
        short count = 0;            // Records the common value counts

        vector<int> ans;            // Records the common value counts at a certain index
        for (int i = 0; i < n; i++)
        {
            short a = ++freq[A[i]]; // The frequency of this value at this point after looking at vector 'A'
            short b = ++freq[B[i]]; // The frequency of this value at this point after looking at vector 'B'

            // If a frequency is greater than 1, this value has been seen in both vectors at this point.
            count = count + (a > 1) + (b > 1);   
            ans.push_back(count);
        }

        return ans;
    }
};
