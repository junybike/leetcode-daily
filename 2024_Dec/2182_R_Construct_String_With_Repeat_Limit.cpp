// 2024 Dec 17

class Solution {
public:
    string repeatLimitedString(string& s, int repeatLimit) 
    {
        // Initialize the string to return
        string ans;             
        ans.reserve(s.size());  

        // Find frequency of each characters in 's'
        int freq[26] = {0};
        for (char c : s) 
        {
            freq[c - 'a']++;
        }

        // Set priority queue. Values (characters) are weighted on their frequency
        priority_queue<char> pq;
        for (int i=0; i<26; i++) 
        {
            if (freq[i] > 0) pq.push('a' + i);
        }
        
        while (!pq.empty()) 
        {
            char c = pq.top();  // Get the most frequent character appearing in 's'. 
            pq.pop();
            
            int& f = freq[c - 'a'];             // The amount of frequency of the character
            int count = min(f, repeatLimit);    

            // Concatenate the character at most 'repeatLimit' times to the 'ans' string.
            // If the frequency is lower than 'repeatLimit', add the character 'c' times.
            // After adding the character 'count' time, reduce the amount of frequency stored in 'freq' 
            ans.append(count, c);               
            f-= count;

            // To keep the characters to not appear more than 'repeatLimit' times in a row, add a character
            if (f > 0) 
            {
                if (pq.empty()) break;      // Case where there are no more characters to append
                
                char c2 = pq.top();         // Get the next most frequent character that appears in 's'.
                ans.push_back(c2);          // Append the character to the 'ans'
                int f2 = --freq[c2 - 'a'];  // Decrement the character frequency by one.

                // Update the frequency value of the character in 'pq'
                if (f2 == 0) pq.pop();
                pq.push(c);                 
            }
        }
        
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/construct-string-with-repeat-limit/solutions/6154436/greedy-make-heap-c-array-vs-priority-queue
*/

class Solution2 {
public:
    string repeatLimitedString(string& s, int repeatLimit) 
    {
        // Sorting characters in 's' in ascending order
        sort(begin(s), end(s), greater<char>());

        string ans = "";        // The string to return
        int n = s.length();     // The length of 's'
        int count = 1;          // A counter
        int index = 0;          // An index to traverse in 's'

        for (int i = 0; i < n; i++)
        {
            // Case where last character of 'ans' and s[i] are the same and 'ans' is not empty string 
            if (!ans.empty() && ans.back() == s[i])
            {
                // Concatenate s[i] to back of 'ans' if the 'count' is below the limit
                if (count < repeatLimit)
                {
                    ans += s[i];
                    count++;
                }
                // The case when 'count' reached the limit 
                else
                {
                    // Updating the index to the first character that is not the same as s[index].
                    index = max(index, i + 1);                      
                    while (index < n && s[index] == s[i]) index++;  

                    // Rearrange location of characters at 'index' and 'i' to maintain the appearance rule of characters
                    // (A specific character should not appear more than 'repeatLimit' times in a row) 
                    if (index < n)
                    {
                        ans += s[index];
                        swap(s[i], s[index]);
                        count = 1;
                    }
                    else break;
                }
            }
            // Case where current character is not the same as previous character.
            else
            {
                ans += s[i];
                count = 1;
            }
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/construct-string-with-repeat-limit/solutions/6154401/two-pointer-simple-solution
*/
