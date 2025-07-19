// 2025 July 19
class Solution {
public:

    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(), folder.end());

        vector<string> ans;
        ans.push_back(folder[0]);
        
        for (int i = 1; i < folder.size(); i++)
        {
            string f = ans.back();
            f += '/';

            // check if current directory starts with the last directory's destination
            if (folder[i].compare(0, f.size(), f) != 0) ans.push_back(folder[i]);
        }

        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/editorial
*/
