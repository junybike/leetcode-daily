// 2025 Apr 18

class Solution {
public:
    string countAndSay(int n) 
    {
        string str = "1";
        for (int i = 1; i < n; i++)
        {
            string newstr = ""; 
            int cnt = 1;
            char c = str[0];    // check how many consecutive 'c' appears 

            for (int j = 1; j < str.size(); j++)
            {
                if (str[j] == c) cnt++; // count the number of consecutive same number
                else 
                {
                    newstr += to_string(cnt) + c;   // compress it by number of consecutive same number + the number  
                    c = str[j]; // move onto next number 
                    cnt = 1;    // reset counter
                }
            }
            // update str
            newstr += to_string(cnt) + c;
            str = newstr;
        }    
        return str;
    }
};
/*
solution reference
https://leetcode.com/problems/count-and-say/solutions/6661672/simple-iterative-solution-hints-java-c-python
*/
