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

    // This function stores all  values in a binary tree into a vector
    void levelorder(TreeNode* root, int level, vector<int>& values)
    {
        if (root == nullptr) return;
        if (level == 1) 
        {
            values.push_back(root->val);
        }
        else if (level > 1)
        {
            levelorder(root->left, level - 1, values);
            levelorder(root->right, level - 1, values);
        }
    }

    // This function determines the height of a binary tree
    int height(TreeNode* root)
    {
        if (root == nullptr) return 0;
        int left = height(root->left);
        return left + 1;
    }

    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        vector<int> values;     // To store all values from 'root' binary tree 
        int h = height(root);   // The height of 'root'
        int n = 0;              // The number of values in 'root'

        // Initialize 'values' and 'n'
        for (int i = 1; i <= h; i++)
        {
            levelorder(root, i, values);
            n += 1 << (i - 1);
        }

        // For each odd numbered floor    
        for (int i = 1; i < h; i += 2)
        {
            int s = (2 << (i - 1)) - 1;     // The current floor's first value's index in 'values' 
            int v = s;                      // The amount of values in this current floor 'i - 1'
            int index = 0;                  // An index in 'values'  
            
            // Reverse the order of values that are located in odd value of levels in binary tree
            int e = s;
            while (index <= v / 2)
            {
                int temp = values[s];
                values[s] = values[e + v - index];
                values[e + v - index] = temp;

                s++;
                index++;
            }
        }

        TreeNode* tree = new TreeNode(values[0]);   // The binary tree to return
        queue<TreeNode*> q;                         // A queue to push the values in from 'values'
        
        q.push(tree);
        int i = 1;
        
        // Push the values from 'values' to 'tree' in level order
        while (i < n)
        {
            TreeNode* temp = q.front();
            q.pop();
            if (i < n)
            {
                temp->left = new TreeNode(values[i++]);
                q.push(temp->left);
            } 
            if (i < n)
            {
                temp->right = new TreeNode(values[i++]);
                q.push(temp->right);
            }
        }
        return tree;
    }
};
