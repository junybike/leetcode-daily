// 2024 Oct 8

class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        // balance = 0: all parentheses are balanced
        // balance > 0: there are more opening parentheses
        // balance < 0: there are more closing parentheses
        int balance = 0;  
        int ans = 0;      // extra parentheses needed 

        for (char c : s)
        {
            if (c == '(') balance++;  // add one to balance if 'c' is opening parentheses
            else balance--;           // subtract one from balance if 'c' is closing parentheses

            // If, at any point, there are more closing parentheses than opening parentheses,
            // pretend to add a new parentheses immediately to keep the balance 0.
            // Increment ans.
            if (balance < 0)   
            {
                ans++;
                balance++;
            }
        }    

        ans += balance; // Add the amount of extra opening parentheses to and. (The amount of extra closing brackets to add)
        return ans;
    }
};
