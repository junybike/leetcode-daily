// 2024 Sept 24

struct TrieNode
{
    int count;
    TrieNode* children[26];
    
    // Constructor (Initialization)
    TrieNode()
    {
        count = 0;
        memset(children, 0, sizeof(children));
    }

    // Add string (prefix) to the TrieNode char by char. Assign new TrieNode for each char 
    void add(string &str, int i)
    {
        if (i) count++; // record the appearance of the prefix 
        if (i == str.length()) return;
        if (!children[str[i] - 'a']) children[str[i] - 'a'] = new TrieNode();
        children[str[i] - 'a']->add(str, i + 1);
    }

    // Search for the string and returns the count
    int search(string &str, int i)
    {
        if (i == str.length()) return count;
        return count + children[str[i] - 'a']->search(str, i + 1);
    }
};

class Solution 
{
public:

    vector<int> sumPrefixScores(vector<string>& words) 
    {
        TrieNode* prefixes = new TrieNode();
        vector<int> ans;

        // Add all possible prefixes for each words 
        for (string &str : words)
        {
            prefixes->add(str, 0);
        }

        // Find each string's all possible prefixes and get the sum of counts
        for (string &str : words)
        {
            ans.push_back(prefixes->search(str, 0));
        }

        return ans;
    }
};

/*
Solution reference
https://leetcode.com/problems/sum-of-prefix-scores-of-strings/solutions/5829926/trie-solution-o-n-k-beats-97-c-python
*/
