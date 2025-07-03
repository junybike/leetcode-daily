// 2025 July 3
class Solution {
public:
    char kthCharacter(int k) 
    {
        string str = "a";
        while (str.length() < k)    // repeat the game until the str reaches length of k
        {
            string tmp = "";
            for (char c : str)  // the process
            {
                tmp += char(c + 1);
            }
            str += tmp;
        }
        return str[k - 1];        
    }
};
