// 2025 June 21
class Solution {
public:
    int minimumDeletions(string word, int k) 
    {
        unordered_map<char, int> umap;  // frequencies for each character in word
        for (char c : word)
        {
            umap[c]++;
        }

        int ans = word.length();
        for (auto& i : umap)        // compare each character's frequencies with all characters
        {
            int cnt = 0;
            for (auto& j : umap)
            {
                if (i.second > j.second) cnt += j.second;  // delete the whole character
                else if (j.second > i.second + k) cnt += j.second - (i.second + k);  // only delete some to make the difference to k 
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};
/*
solution reference
https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/editorial
*/
