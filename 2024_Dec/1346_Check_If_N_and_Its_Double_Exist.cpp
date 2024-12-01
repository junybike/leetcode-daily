// 2024 Dec 1

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_map<int, int> umap;  // Store the value observed with its index in 'arr'
        int index = 1;                 // Index counter
        
        // Fill the 'umap'. (the value, its index + 1)
        for (int i : arr)
        {
            umap[i] = index;
            index++;
        } 

        // Check if there is some value A and value B where 2 * A = B 
        // If there is one, return true. If no pair is found, return false.
        // (index of A cannot be the same as index of B) 
        index = 1;
        for (int i : arr)
        {
            if ((umap[i * 2] > 0 && umap[i * 2] != index))
            {
                return true;
            }
            index++;
        }
        return false;   
    }
};
