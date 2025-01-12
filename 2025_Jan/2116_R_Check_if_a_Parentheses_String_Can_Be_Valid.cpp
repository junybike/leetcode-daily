// 2025 Jan 12

class Solution {
public:
    bool canBeValid(string s, string locked) 
    {
        int n = s.length();             // The length of 's'
        if (n % 2 != 0) return false;   // Odd number of parentheses length cannot be balanced. Return false. 

        stack<int> op;      // Store all opening parentheses
        stack<int> unlock;  // Store all unlocked parentheses

        for (int i = 0; i < n; i++)
        {
            if (locked[i] == '0') unlock.push(i);   // If an unlocked parenthese, push it in 'unlock'
            else if (s[i] == '(') op.push(i);       // If an opening parenthese, push it in 'op'
            else if (s[i] == ')')                   // If a closing parenthese, try to balance it by...
            {
                if (!op.empty()) op.pop();              // Remove an opening parenthese if there exists at least one
                else if (!unlock.empty()) unlock.pop(); // Use an unlocked parenthese if there exists at least one
                else return false;                      // Fail to balance. Return false.
            }
        }

        // Balance the parentheses by popping opening and unlocked parentheses at the same time until unlocked parentheses run out.
        while (!op.empty() && !unlock.empty() && op.top() < unlock.top())
        {
            op.pop();
            unlock.pop();
        }

        // If only unlocked parentheses are left, return true if the number of unlocked parenthses are even. Else, cannot balance. Return false.
        if (op.empty() && !unlock.empty()) return op.size() % 2 == 0;

        // If opening parentheses are stil present after popping all unlocked parentheses, return false. Else, return true.
        return op.empty();
    }
};
/*
solution reference
https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/solutions/6267067/simple-balance-2-methods-detailed-solution
*/
