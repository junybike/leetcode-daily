// 2024 Sept 19

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) 
    {
        vector<int> ans;
        int size = expression.size();

        for (int i = 0; i < size; i++)
        {
            char opr = expression[i];

            // Case where opr is holding an operation
            if (opr == '+' || opr == '-' || opr == '*')
            {
                // Split into 2 substring. length of i substring and the size - i substring
                string str1 = expression.substr(0, i);
                string str2 = expression.substr(i + 1);
                
                // Recursive calls on the two substring
                vector<int> s1 = diffWaysToCompute(str1);
                vector<int> s2 = diffWaysToCompute(str2);

                // Perform arithmetic calculations on the substrings
                for (int x : s1)
                {
                    for (int y : s2)
                    {
                        if (opr == '+') ans.push_back(x + y);
                        else if (opr == '-') ans.push_back(x - y);
                        else if (opr == '*') ans.push_back(x * y);
                    }
                } 
            }
        }
        
        // If the expression is a single number, add the number to ans.
        if (ans.size() == 0) ans.push_back(stoi(expression));
        
        return ans;
    }
};

/*
Soultion Reference
https://leetcode.com/problems/different-ways-to-add-parentheses/solutions/5806448/beats-90-beginner-friendly-python3-java-c-c-rust-go-js
*/
