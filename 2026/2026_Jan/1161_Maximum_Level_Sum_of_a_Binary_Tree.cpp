// 2026 Jan 6
class Solution {
public:

    void traverse(TreeNode* root, vector<int>& sums, int level)
    {
        if (!root) return;
        sums[level] += root->val;   // sum up at the current level

        traverse(root->left, sums, level + 1);
        traverse(root->right, sums, level + 1);
    }

    int getheight(TreeNode* root)   // finds height of the tree
    {
        if (!root) return -1;

        int L = getheight(root->left);
        int R = getheight(root->right);

        return max(L, R) + 1;
    }

    int maxLevelSum(TreeNode* root) 
    {
        vector<int> sums(10000, 0); // sums[i] = sum of values at level i
        int level = 0;              // current level
        
        sums[level] += root->val;   // sum[0]
        
        traverse(root->left, sums, level + 1);  // recursively sum up values at each level
        traverse(root->right, sums, level + 1);

        int h = getheight(root);    // the height of the tree
        // cout << h << endl;

        int maxval = INT_MIN;       // the max level sum
        for (int i = 0; i <= h; i++)
        {
            int val = sums[i];
            if (maxval < val)   // find the max level sum and keep track of the level
            {
                maxval = val;
                level = i + 1;
            }
        }
        return level;
    }
};
