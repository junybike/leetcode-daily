// 2025 Feb 21

class FindElements {
public:

    unordered_set<int> uset;    // to indicate value existance at certain location in Tree

    FindElements(TreeNode* root) 
    {
        bfs(root);  // Find all existing locations in Tree
    }
    
    bool find(int target) 
    {
        // Search for target in Tree
        return uset.find(target) != uset.end();    
    }

    void bfs(TreeNode* root)
    {
        queue<TreeNode*> q; // TreeNode to visit
        root->val = 0;      // Set root to 0
        q.push(root);       // Pushing root to 'q'

        while (!q.empty())
        {
            TreeNode* cur = q.front();  // the current TreeNode
            q.pop();                    

            uset.insert(cur->val);      // store this location in uset
            if (cur->left) 
            {
                cur->left->val = cur->val * 2 + 1;  // assign the location of current's left value location
                q.push(cur->left);                  // push this TreeNode to 'q'
            }
            if (cur->right)
            {
                cur->right->val = cur->val * 2 + 2; // assign the location of current's right value location
                q.push(cur->right);                 // push this TreeNode to 'q'
            }
        }
    }
};

/*
solution reference
https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/editorial
*/
