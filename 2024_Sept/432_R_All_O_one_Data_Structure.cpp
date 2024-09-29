// 2024 Sept 28

class AllOne {

    unordered_map<string, int> umap;    // Map from string to the amount of appearance of the string.
    set<pair<int, string>> sorted;      // Sorted set of appearance of strings.

public:
    AllOne() 
    {
        sorted.clear();  // Sorted set initialization.
    }
    
    void inc(string key) 
    {
        int count = umap[key];
        umap[key]++;

        sorted.erase({count, key});         // Remove old pair in the set.
        sorted.insert({count + 1, key});    // Add new pair on the set.
    }
    
    void dec(string key) 
    {
        int count = umap[key];
        umap[key]--;

        sorted.erase({count, key});         // Remove old pair in the set.

        // If the appearance goes to zero, remove the pair in the umap. If not, add new pair on the set.
        if (umap[key] > 0 ) sorted.insert({count - 1, key});
        else umap.erase(key);    
    }
    
    string getMaxKey() 
    {
        if (sorted.empty()) return "";      // Return nothing if the sorted set is empty.
        return sorted.rbegin()->second;     // The string in the last pair (most appearance)
    }
    
    string getMinKey() 
    {
        if (sorted.empty()) return "";      // Return nothing if the sorted set is empty.
        return sorted.begin()->second;      // The string in the first pair (least appearance)
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

 /*
 Solution Reference
 https://leetcode.com/problems/all-oone-data-structure/solutions/5845777/optimize-your-code-with-the-all-o-one-data-structure-hack
 */
