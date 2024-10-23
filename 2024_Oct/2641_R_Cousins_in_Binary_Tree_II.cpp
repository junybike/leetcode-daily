// 2024 Oct 23

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

    void dfs(vector<TreeNode*> tree)
    {
        if (tree.empty()) return;

        int sum = 0; // Sum of values at a certain level
        for (auto node : tree) // Gets the total sum of values at the same level
        {
            if (!node) continue;
            if (node->left) sum += node->left->val;
            if (node->right) sum += node->right->val;
        }

        // Replace the values for corresponding cousins at the same level
        // 'sum' - 'current' = sum of all node's cousins' value
        // where 'sum' is sum of all node at the same level
        // and 'current' is sum of all cousin's value
        vector<TreeNode*> subtree;
        for (auto node : tree)
        {
            int current = 0;
            if (node->left) current += node->left->val;
            if (node->right) current += node->right->val;

            if (node->left)
            {
                node->left->val = sum - current;
                subtree.push_back(node->left);  // Get the lower level node and store it into 'subtree' vector
            }
            if (node->right)
            {
                node->right->val = sum - current;
                subtree.push_back(node->right); // Get the lower level node and store it into 'subtree' vector
            }
        }
        
        // Repeat for the remaining levels in the tree
        dfs(subtree);
    }

    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        root->val = 0;
        dfs(vector<TreeNode*>{root});
        return root;    
    }
};

/*
solution reference
https://leetcode.com/problems/cousins-in-binary-tree-ii/solutions/5955106/beats-100-00-explained-with-example
*/
