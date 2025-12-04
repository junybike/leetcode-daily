// 2025 June 15 
class Solution {
public:
    int maxDiff(int num) {
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

        char minchar;   // find which number should be replaced by 1 or 0 to make min value
        bool first = false; // if true, replace numbers with 1 because we cannot replace first digit with 0. if false, replace numbers with 0. 
        for (int i = 0; i < minstr.length(); i++)
        {
            if (minstr[i] != '1' && minstr[i] != '0')   // skips trailing 1 and 0. 
            {
                // cout << minstr[i] << " ";
                minchar = minstr[i];
                if (i == 0) first = true;
                break;
            }
        }

        // cout << maxstr << " " << minstr << " " << first;

        for (int i = 0; i < maxstr.length(); i++)
        {
            if (maxchar == maxstr[i]) maxstr[i] = '9';  // replace all numbers that are same as maxchar with 9
            if (minchar == minstr[i] && first) minstr[i] = '1';  // replace all numbers that are same as minchar with 1
            else if (minchar == minstr[i] && !first) minstr[i] = '0';   // replace all numbers that are same as minchar with 1 if first digit is 1.
        }

        // cout << maxstr << " " << minstr;

        return stoi(maxstr) - stoi(minstr); // max diff
    }
};
