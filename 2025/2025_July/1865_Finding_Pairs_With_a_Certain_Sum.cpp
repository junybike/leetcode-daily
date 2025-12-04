// 2025 July 6

class FindSumPairs {

private:

    vector<int> v1;
    vector<int> v2;
    unordered_map<int, int> umap;

public:

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        for (int i : nums2) umap[i]++;  // store the frequency for each values in nums2
        v1 = nums1;
        v2 = nums2;      
    }
    
    void add(int index, int val) 
    {
        int i = v2[index];
        
        // Manage the frequency and update the value in v2
        umap[i]--;
        v2[index] = i + val;
        umap[i + val]++;
    }
    
    int count(int tot) 
    {
        int cnt = 0;
        for (int i : v1)    // for each value in v1, find number of values in v2 that can be summed to 'tot'
        {
            if (umap[tot - i]) cnt += umap[tot - i];
        }
        return cnt;
    }
};
