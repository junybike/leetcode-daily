// 2025 Mar 2

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        short i1 = 0;   // an index for iterating values in 'nums1' 
        short i2 = 0;   // an index for iterating values in 'nums2'

        vector<vector<int>> ans;    // to return the merged 'nums1' and 'nums2'

        while (i1 < nums1.size() && i2 < nums2.size())  
        {
            if (nums1[i1][0] < nums2[i2][0])    // If current nums1 array id is less than current nums2 array id, 
            {                                   // append the current nums1 array to ans and increment the index i1
                ans.push_back(nums1[i1]);
                i1++;
            }
            else if (nums1[i1][0] > nums2[i2][0])   // If current nums2 array id is less than current nums1 array id, 
            {                                       // append the current nums2 array to ans and increment the index i2
                ans.push_back(nums2[i2]);
                i2++;
            }
            else                                    // If the two array id are the same, sum up the values in the arrays
            {                                       // and append the id and its summed up values to ans. Updates the indexes
                nums1[i1][1] += nums2[i2][1];
                ans.push_back(nums1[i1]);
                i1++;
                i2++;
            }
        }

        // Append remaining id and its value in one of the vectors
        while (i1 < nums1.size())
        {
            ans.push_back(nums1[i1]);
            i1++;
        }
        while (i2 < nums2.size())
        {
            ans.push_back(nums2[i2]);
            i2++;
        }

        return ans;
    }
};
