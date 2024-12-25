// 2024 Dec 25

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

    vector<int> ans;    // To store the greatest value in each binary tree level 
    
    // Find the greatest value in each binary tree level
    void preorder(TreeNode* node, int level)
    {
        if (node == nullptr) return;
        if (ans.size() <= level) ans.push_back(INT_MIN);    // temporary placeholder for this level's greatest value

        // Update the greatest value at this level if greater value is found at this level
        ans[level] = max(ans[level], node->val);

        // Find the next level's greatest value
        preorder(node->left, level + 1);
        preorder(node->right, level + 1);
    }

    vector<int> largestValues(TreeNode* root) 
    {
        if (root == nullptr) return {};
        preorder(root, 0);
        return ans;
    }
};

/*
solution reference
https://leetcode.com/problems/find-largest-value-in-each-tree-row/solutions/6183093/preorder-transversal-vs-level-bfs-beats-100
*/
