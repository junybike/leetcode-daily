// 2024 Dec 23

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode*> q; // To store a specific level's tree nodes. 
        q.push(root);       // Push the 'root' to the 'q'
        int swaps = 0;      // To record the number of swaps

        // DFS to traverse level by level
        while (!q.empty())
        {
            int n = q.size();                       // The size of 'q'
            vector<int> arr(n, 0);                  // Store the values present in this level
            vector<int> index(n, 0);                // Store the indexes in 'q'
            iota(index.begin(), index.end(), 0);    // Set 'index' vector containing "1, 2, 3 ... n"

            // Store all values in this level into 'arr'
            for (int i = 0; i < n; i++)
            {
                // Assign the values to 'arr'
                TreeNode* node = q.front();
                q.pop();
                arr[i] = node->val;

                // Push the current node's childs to 'q' for the next level's value assigning to 'arr'
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // Sort the index by comparing the values they are holding in 'arr'
            sort(index.begin(), index.end(), [&](int i, int j) {return arr[i] < arr[j];});

            // Record the number of swaps needed to sort the values at this level
            for (int i = 0; i < n;)
            {
                int j = index[i];
                if (j != i)
                {
                    swaps++;
                    swap(index[i], index[j]);
                }
                else i++;
            }
        }
        return swaps;
    }
};

/*
solution reference
https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/solutions/6175677/bfs-levelwise-transversal-compare-with-sorted-or-dfs-cycle-lengths-29-ms-beats-97-95
*/
