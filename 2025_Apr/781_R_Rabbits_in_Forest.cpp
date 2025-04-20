// 2025 Apr 20

class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int, int> umap;
        int cnt = 0;

        // each umap[i] represents frequency getting: "i number of same color rabbits other than me" 
        for (int i : answers)   
        {
            umap[i]++; 
        }    
        for (auto i : umap)
        {   //                         different color group
            cnt += ceil((double)i.second / (i.first + 1)) * (i.first + 1);
        }
        return cnt;
    }
};
/*
solution reference
https://leetcode.com/problems/rabbits-in-forest/solutions/6668336/hashmap-with-images-example-walkthrough-c-python-java
*/
