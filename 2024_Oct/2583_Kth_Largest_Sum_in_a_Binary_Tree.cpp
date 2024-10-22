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

    unordered_map<int, long long> umap;  // To store sums of values at each level of Tree

    // Recursive function to get the sum of values at a level of Tree
    void getlevelsum(TreeNode* node, int level)
    {
        if (node == NULL) return;  // Case of empty node: does nothing.
        umap[level] += node->val;  // Add the current node's value for this level.

        // Move on to the next level
        getlevelsum(node->left, level + 1);
        getlevelsum(node->right, level + 1);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        getlevelsum(root, 0);  // Calculates sums of values at each level of Tree

        // Move each sums at each level to a vector
        vector<long long> sums;
        for (auto i : umap) sums.push_back(i.second);

        // If the height of tree is shorter than k, return -1. Impossible to get kth largest sum.
        if (sums.size() < k) return -1;

        // Sort the sums in descending order
        sort(sums.begin(), sums.end(), greater<long long>());

        // Return kth largest sum
        return sums[k - 1];
    }
};
