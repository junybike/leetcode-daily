// 2025 May 4

class Solution {
public:

    // for making unordered_map with pair as its key 
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1,T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            // Mainly for demonstration purposes, i.e. works but is overly simple
            // In the real world, use sth. like boost.hash_combine
            return h1 ^ h2;  
        }
    };

    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        // store frequencies of each dominoes regardless of its order (1,2 and 2,1 are same)
        unordered_map<pair<int, int>, int, pair_hash> umap;
        int cnt = 0;

        // record the frequencies for dominoes
        for (auto& i : dominoes)
        {
            int first = i[0];
            int second = i[1];

            if (first < second) swap(first, second);
            umap[{first, second}]++;
        }    

        // for each dominoes, count the "pairs" and add to 'cnt'
        for (auto& i : umap)
        {
            int tmp = i.second;
            if (tmp > 1) cnt += tmp * (tmp - 1) / 2; 
        }
        return cnt;
    }
};
