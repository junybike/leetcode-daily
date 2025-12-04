// 2025 June 2
class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        int cnt = 0;

        vector<int> left(n, 1);     // Keep track of candy each child need to get if iterating from the left
        vector<int> right(n, 1);    // Keep track of candy each child need to get if iterating from the right

        for (int i = 1; i < n; i++)
        {
            // if rating on the right child of current child is greater, set right child's candy to be current child's candy + 1 (iterating from the left)
            if (ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1; 
            // if rating on the left child of current child is greater, set left child's candy to be current child's candy + 1 (iterating from the right)
            if (ratings[n - i - 1] > ratings[n - i]) right[n - i - 1] = right[n - i] + 1;
        }
        for (int i = 0; i < n; i++)
        {
            // compare left and right vector and check which one requires more candy for each child. Add the one that requires more candy
            if (left[i] > right[i]) cnt += left[i]; 
            else cnt += right[i];                   
        }

        return cnt;
    }
};
