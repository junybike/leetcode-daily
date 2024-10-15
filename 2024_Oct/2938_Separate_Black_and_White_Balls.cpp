// 2024 Oct 15

class Solution {
public:
    long long minimumSteps(string s) 
    {
        long long ans = 0;  // Tracking the number of swaps needed
        int temp = 0;       // Tracking how much a black ball is misplaced at a spot

        for (int i = s.length(); i >= 0; i--)
        {
            // White ball case:
            // Increment the temp whenever a white ball is spotted.
            if (s[i] == '0') temp++;

            // Black ball case:
            // If there is a black ball, add the 'temp' to 'ans', 
            // which represents the number of swaps needed to put the ball in the right place
            // (when 'temp' is 0, the black ball is at the right-most spot. Therefore, no change is made to 'ans')
            else if (s[i] == '1') ans += temp;
        }
        return ans;
    }
};
