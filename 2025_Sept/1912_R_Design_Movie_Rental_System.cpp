// 2025 Sept 21 2025

using int2 = pair<int, int>;        // price, shop
using int3 = tuple<int, int, int>;  // price, shop, movie

class MovieRentingSystem {
public:

    unordered_map<uint64_t, int> shop_list;     // (shop, movie) -> price
    unordered_map<int, set<int2>> movie_list;   // movie -> set(price, shop)
    set<int3> rented;                           // rented -> set(price, shop, movie)

    static inline uint64_t key(int shop, int movie) {
        return (uint64_t)shop<<32|movie;
    }

    MovieRentingSystem(int n, vector<vector<int>>& entries) 
    {
        for (auto& e : entries)
        {
            int shop = e[0];
            int movie = e[1];
            int price = e[2];

            shop_list[key(shop, movie)] = price;
            movie_list[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) 
    {
        vector<int> ans;
        auto& s = movie_list[movie];

        int i = 0;
        for (auto it = s.begin(); it != s.end() && i < 5; it++, i++)
        {
            ans.push_back(it->second);
        }    
        return ans;
    }
    
    void rent(int shop, int movie) 
    {
        int price = shop_list[key(shop, movie)];
        movie_list[movie].erase({price, shop});
        rented.insert({price, shop, movie});    
    }
    
    void drop(int shop, int movie) 
    {
        int price = shop_list[key(shop, movie)];
        movie_list[movie].insert({price, shop});
        rented.erase({price, shop, movie});    
    }
    
    vector<vector<int>> report() 
    {
        vector<vector<int>> ans;
        int i = 0;
        for (auto it = rented.begin(); it != rented.end() && i < 5; it++, i++)
        {
            auto [price, shop, movie] = *it;
            ans.push_back({shop, movie});
        }    
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */

/*
solution reference
https://leetcode.com/problems/design-movie-rental-system/solutions/7209432/hashmaps-ordered-sets-202ms-beats-98-54
*/
