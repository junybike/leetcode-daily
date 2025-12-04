// 2024 Nov 23

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int W = box[0].size();  // The size of columns
        int H = box.size();     // The size of rows

        // The rotated box to return. Initialize with all cell filled with air
        vector<vector<char>> ans(W, vector<char>(H, '.'));  
        
        for (int i = 0; i < H; i++)
        {
            // Count of encountered air (.) before reaching the next box (#)
            int emp = 0;
            for (int j = W - 1; j >= 0; j--)
            {
                // If current cell contains an air, increment the 'emp' and move on to the next cell
                if (box[i][j] == '.')
                {
                    emp++;
                    continue;
                } 

                // If current cell contains a stationary, reset the 'emp' 
                // and store the stationary to rotated position at 'ans'   
                // Move on to the next cell
                if (box[i][j] == '*')
                {
                    emp = 0;
                    ans[j][H - i - 1] = '*';
                    continue;
                }

                // If a box (#) is encountered at the right most index at 'box',
                // store the box to rotated position at 'ans' (at the very bottom). 
                // Move on to the next cell.
                if (j == W - 1 && box[i][j] == '#')
                {
                    emp = 0;
                    ans[j][H - i - 1] = '#';
                    continue;
                }

                // Assign the box at the position where the very first air was spotted after # or *.
                // Assign the air at the box position.
                ans[j][H - i - 1] = '.';
                ans[j + emp][H - i - 1] = '#';
            }
        }
        return ans;
    }
};

