// 2024 Oct 20

class Solution {
public:
    bool parseBoolExpr(string expression) 
    {
        stack<char> st;

        for (char c : expression)
        {
            // Skips when 'c' is a , or (.
            if (c == ',' || c == '(') continue;

            // Add on top of 'st' when 'c' is not a , or (.
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') st.push(c);
            
            // Start to evaluate when encounters a closing paranthesis.
            else if (c == ')')
            {
                bool hasTrue = false;   // Indicator of existance of value t
                bool hasFalse = false;  // Indicator of existance of value f

                // Check for value t and f until it encounters an operator value.
                while (st.top() != '!' && st.top() != '&' && st.top() != '|')
                {
                    char topvalue = st.top();
                    st.pop();
                    if (topvalue == 't') hasTrue = true;    // Set 'hasTrue' true if a value t is found
                    if (topvalue == 'f') hasFalse = true;   // Set 'hasFalse' true if a value f is found
                }

                char op = st.top(); // The operator to evaluate
                st.pop();

                // Evaluating logical NOT of inner expression. 
                // If contains true, push value f on the top of stack. Push t otherwise.
                if (op == '!') st.push(hasTrue ? 'f' : 't');

                // Evaluating logical AND of the inner expression.
                // But no matter how many values there are, existance of one f will make the whole thing f.
                // So if hasFalse is true, push value f on the top of stack. Push t otherwise.
                else if (op == '&') st.push(hasFalse ? 'f' : 't');

                // Evaluating logical OR of the inner expression.
                // But no matter how many values there are, existance of one t will make the whole thing t.
                // So if hasTrue is true, push value t on the top of stack. Push f otherwise.
                else st.push(hasTrue ? 't' : 'f');
            }
        }
        return st.top() == 't';
    }
};

/*
Solution reference
https://leetcode.com/problems/parsing-a-boolean-expression/solutions/5939345/beats-100-optimized-solution-python-java-c-o-n-o-n
*/
