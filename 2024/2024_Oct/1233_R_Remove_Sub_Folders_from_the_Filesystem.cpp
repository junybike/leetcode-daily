// 2024 Oct 25

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        // Sorting the folder vector lexicographically
        // Folders with minimum sub folders at first.
        sort(folder.begin(), folder.end());

        // List of folders to return.
        // First folder is put as default, since it cannot be one's subfolder
        vector<string> ans = {folder[0]};

        string prev = folder[0];    // To find another folder that is a subfolder of 'prev' folder
        int n = folder.size();      // Size of folder vector

        for (int i = 1; i < n; i++)
        {
            // If 'temp' folder does not contains the 'prev',
            // push that 'temp' folder into the 'ans' vector.
            // Update the 'temp' to be recently added folder to 'ans'
            // and start checking subfolders based on that folder 
            string temp = folder[i];
            if (temp.find(prev + '/') != 0)
            {
                ans.push_back(temp);
                prev = temp;
            }
        }
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/solutions/5964733/sort-strings-vs-trie-56-ms-beats-92-86
*/
