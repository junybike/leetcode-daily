// 2024 Oct 24
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

    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        // If the two nodes to compare are both NULL, the subtree upto this point is flip equivalent
        // If only one of the two node is NULL, the two trees are not flip equivalent
        if (root1 == NULL || root2 == NULL) return root1 == root2;

        // The case where the two values are not equal.
        // Then the two binary trees are not flip equivalent. Return false.
        if (root1->val != root2->val) return false;

        // (the left subtree of tree1 and tree2) are equivalent 
        // and (right subtree of tree1 and tree2) are equivalent 
        // OR
        // (left subtree of tree1 and right subtree of tree2) are equivalent 
        // and (right subtree of tree1 and left subtree of tree2) equivalent
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
                (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));  
    }
};

/*
solution reference
https://leetcode.com/problems/flip-equivalent-binary-trees/solutions/5960058/c-solution-simple-dfs-beats-100
*/
