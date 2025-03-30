// 2025 Mar 30

class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> index(26, 0);               // stores last occurance index for each characters
        for (int i = 0; i < s.length(); i++)    
        {
            index[s[i] - 'a'] = i;
        }    

        vector<int> ans;    // stores sizes of each partition
        int start = 0;      // index of first character that a partition wants to include
        int end = 0;        // index of last character that a partition wants to include 

        for (int i = 0; i < s.length(); i++)
        {
            // updates last character that partition wants to include if current character's last occurance is later than current 'end'
            if (end < index[s[i] - 'a']) end = index[s[i] - 'a'];   
            
            // if the loop iteration reaches to the 'end', make a new partition and update 'start' to next index
            if (i == end) 
            {
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};
