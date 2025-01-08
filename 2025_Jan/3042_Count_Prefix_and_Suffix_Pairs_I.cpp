// 2025 Jan 8

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int n = words.size();   // The amount of word in 'words'
        int ans = 0;            // The number of pairs to return

        for (int i = 0; i < n; i++)
        {
            // The target word to see if any other words that appears later than the 'target' contains the 'target' as prefix and suffix
            string& target = words[i];  

            for (int j = i + 1; j < n; j++)
            {
                // The word to check if this word contains 'target' as its prefix and suffix
                // If the target is larger than the word, impossible case. Skip.
                string& word = words[j];        
                if (target.length() > word.length()) continue;

                // Determines if the word contains the 'target' as its prefix and suffix
                auto res = mismatch(target.begin(), target.end(), word.begin());
                bool isprefix = (res.first == target.end());
                bool issuffix = (0 == word.compare(word.length() - target.length(), target.length(), target));
                
                if (isprefix && issuffix) ans++;    // Increment 'ans' if the word contains the 'target' as its prefix and suffix
            }
        }       
        return ans;
    }
};
