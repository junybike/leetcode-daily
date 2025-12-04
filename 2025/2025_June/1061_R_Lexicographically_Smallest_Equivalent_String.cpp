// 2025 June 5

class UnionFind {

    vector<int> root;

public:
    
    UnionFind(int n) : root(n)  // constructor
    {
        iota(root.begin(), root.end(), 0);
    }
    
    int u_find(int i)   // find the lexicographically lowest character that this character has access to
    {
        return (i == root[i]) ? i : root[i] = u_find(root[i]);
    }
    
    void u_union(int i, int j)  // replace the lexicographically lowest character that this character can get to
    {
        i = u_find(i);
        j = u_find(j);

        if (i == j) return;
        else if (i < j) root[j] = i;
        else root[i] = j;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        UnionFind uf(26);

        for (int i = 0; i < s1.length(); i++)   // for each character that are present in s1 and s2, perform the UnionFind
        {
            uf.u_union(s1[i] - 'a', s2[i] - 'a');
        }

        for (int i = 0; i < baseStr.length(); i++)  // replace each characters in baseStr if a character has access to lexicographically lower character 
        {
            baseStr[i] = 'a' + uf.u_find(baseStr[i] - 'a');
        }
        return baseStr;
    }
};
/*
solution reference
https://leetcode.com/problems/lexicographically-smallest-equivalent-string/solutions/6812007/unionfind-vs-dfs-for-the-equivalent-relation-beats-100
*/
