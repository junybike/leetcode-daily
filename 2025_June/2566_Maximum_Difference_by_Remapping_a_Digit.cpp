// 2025 June 14

class Solution {
public:
    int minMaxDifference(int num) 
    {
        string maxstr = to_string(num); // to find possible max value
        string minstr = maxstr;         // to find possible min value

        char maxchar;   // find which number should be replaced by 9 to make max value
        for (int i = 0; i < maxstr.length(); i++)
        {
            if (maxstr[i] != '9') // if 9 is the first digit or possibly multiple first digits of 9, find the non-nine digit that comes after  
            {
                maxchar = maxstr[i];
                break;
            }
        }

        char minchar = maxstr[0];   // find which number should be replaced by 0.
        for (int i = 0; i < maxstr.length(); i++)
        {
            if (maxchar == maxstr[i]) maxstr[i] = '9';  // replace all numbers that are same as maxchar with 9
            if (minchar == minstr[i]) minstr[i] = '0';  // replace all numbers that are same as the first digit
        }

        return stoi(maxstr) - stoi(minstr); // max diff
    }
};
