// 2026 Jan 7
class Solution {
public:

    long long MOD = 1e9 + 7;
    long long totalsum = 0;     // the sum of all values in the tree
    long long best = 0;         // the best product of 2 sub trees

    long long get_total(TreeNode* root) // computes the sum of all values in the tree
    {
        if (!root) return 0;
        
        long long L = get_total(root->left);
        long long R = get_total(root->right);

        return L + R + root->val;
    }

    long long find_max(TreeNode* root)  // traverse and finds the best product of 2 sub trees
    {
        if (!root) return 0;
        long long L = find_max(root->left);
        long long R = find_max(root->right);

        long long subsum = L + R + root->val;  // current subtree's sum

        // check current 2 sub trees' product with best and replace best if a greater product is found
        best = max(best, (subsum * (totalsum - subsum))); 
        return subsum;
    }

    int maxProduct(TreeNode* root) 
    {
        totalsum = get_total(root);
        find_max(root);
        return best % MOD;
    }
};
