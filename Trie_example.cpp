struct Trie 
{
    Trie* next[26];
    bool isEnd = 0;

    Trie() 
    {
        fill(next, next + 26, (Trie*)NULL);
    }

    ~Trie() 
    {
        for (int i = 0; i < 26; ++i) 
        {
            if (next[i] !=NULL) 
            {
                delete next[i];
            }
        }
    }

    void insert(string& word) 
    {
        Trie* Node = this;
        for(char c: word)
        {
            int i = c - 'a';
            if(Node->next[i] == NULL) Node->next[i] = new Trie();
            Node = Node->next[i];
        }
        Node->isEnd = 1;
    }
};

class Solution {
public:

    int prefixCount(vector<string>& words, string pref) 
    {
        Trie trie;
        int ans = 0;

        trie.insert(pref);

        for (string& s : words)
        {
            Trie* node = &trie;
            for (char& c : s)
            {
                int index = c - 'a';
                if (node->next[index] == NULL) break;
                
                node = node->next[index];
                if (node->isEnd) ans++;
            }
        }
        return ans;
    }
};
