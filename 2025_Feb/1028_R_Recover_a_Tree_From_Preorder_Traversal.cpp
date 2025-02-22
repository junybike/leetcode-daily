// 2025 Feb 22

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) 
    {
        stack<pair<TreeNode*, int>> st; // stores pair of TreeNode and its height in BST
        TreeNode* root = nullptr;       // the root node of BST

        int i = 0;                      // index variable
        int n = traversal.length();     // length of 'traversal'

        while (i < n)
        {
            int h = 0;                              // current height
            while (i < n && traversal[i] == '-')    // find out the height of th next value in 'traversal'
            {
                h++;
                i++;
            }

            int value = 0;                                  // the node's value
            while (i < n && isdigit(traversal[i]))          // find the node's value
            {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(value);           // make new node for this value
            if (h == 0) root = node;
            else
            {
                while (st.size() > h) // pops nodes from the 'st' until its parent is found
                {
                    st.pop();
                }
                if (st.top().first->left == nullptr) st.top().first->left = node;
                else st.top().first->right = node;
            }
            st.push({node, h});
        }    
        return root;
    }
};

class Solution2 {
public:

    TreeNode* helper(const string& traversal, int& index, int depth)
    {
        if (index >= traversal.length()) return nullptr;

        // Find the number of dashes
        int cnt = 0;
        while (index + cnt < traversal.length() && traversal[index + cnt] == '-')
        {
            cnt++;
        }
        
        if (cnt != depth) return nullptr;   // Case where number of dash != depth
        index += cnt;

        // Find the value of the current node
        int value = 0;
        while (index < traversal.length() && isdigit(traversal[index]))
        {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }
        
        // Builds the left and right subtrees
        TreeNode* node = new TreeNode(value);
        node->left = helper(traversal, index, depth + 1);
        node->right = helper(traversal, index, depth + 1);

        return node;
    }

    TreeNode* recoverFromPreorder(string traversal) 
    {
        int index = 0;
        return helper(traversal, index, 0);
    }
};

/*
solution reference
https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/editorial
*/
