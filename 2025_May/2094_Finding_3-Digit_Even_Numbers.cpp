// 2025 May 12
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) 
    {
        int freq[10] = {0};     // Stores frequency of each digits
        for (int& i : digits)   // Finds the frequencies
        {
            freq[i]++;
        } 

        vector<int> ans;                    // stores possible numbers that can be formed from the digits
        for (int i = 100; i <= 999; i+=2)
        {   
            int num = i;
            int i1 = num % 10;  // the first digit
            num /= 10;

            freq[i1]--;         // remove it from the freq temporarily
            if (freq[i1] < 0)   // check if freq for this digit goes below 0
            {
                freq[i1]++;     // if goes below 0, the current number can't be formed
                continue;       // restore the freq for this digit and move on to next number
            }

            int i2 = num % 10;  // the second digit
            num /= 10;

            freq[i2]--;
            if (freq[i2] < 0)
            {
                freq[i1]++;
                freq[i2]++;
                continue;
            }

            int i3 = num % 10;  // the third digit
            num /= 10;
            
            freq[i3]--;
            if (freq[i3] < 0)
            {
                freq[i1]++;
                freq[i2]++;
                freq[i3]++;
                continue;
            }

            ans.push_back(i);   // the current number can be formed. add it to the vector
            freq[i1]++;
            freq[i2]++;
            freq[i3]++;
        }
        return ans;
    }
};
