// 2025 Jan 25

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        int n = nums.size();                // size of 'nums'
        vector<int> sorted(nums);           // copy of 'nums'  
        sort(sorted.begin(), sorted.end()); // sort values in 'sorted' in ascending order

        // values are in the same group if they ascend no more than limit.
        // Example with limit = 3 and nums: 1 2 5 7 10 15 17 19 
        // The first group would be: 1 2 5 7 10 (each ascended by no more than 3.)
        // Another group would be: 15 17 19 (separated from others since 10 and 15 is a jump more than 3)

        int groupid = 0;                    // to track the number of groups
        unordered_map<int, int> numToGroup; // to assign each values a 'groupid'
        numToGroup[sorted[0]] = groupid;    // assign the first value in 'sorted' to groupid 0

        unordered_map<int, list<int>> groupToList;      // to group the values (values in each group maintains ascending order)
        groupToList[groupid] = list<int>(1, sorted[0]); 

        for (int i = 1; i < n; i++) 
        {
            // If there is a jump larger than limit, move on to the next group 
            if (abs(sorted[i] - sorted[i - 1]) > limit) groupid++;  
            numToGroup[sorted[i]] = groupid;

            // If groupid hasn't been pushed to groupToList, make a new list for this group
            if (groupToList.find(groupid) == groupToList.end()) groupToList[groupid] = list<int>();
            groupToList[groupid].push_back(sorted[i]);
        }

        for (int i = 0; i < n; i++) 
        {
            int num = nums[i];
            int group = numToGroup[num];

            // Overwriting the values in group to the original 'nums' 
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};

/*
solution reference
https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/editorial
*/
