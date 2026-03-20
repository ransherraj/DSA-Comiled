/***
3212. Count Submatrices With Equal Frequency of X and Y
Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

grid[0][0]
an equal frequency of 'X' and 'Y'.
at least one 'X'.
 

Example 1:

Input: grid = [["X","Y","."],["Y",".","."]]

Output: 3

Explanation:



Example 2:

Input: grid = [["X","X"],["X","Y"]]

Output: 0

Explanation:

No submatrix has an equal frequency of 'X' and 'Y'.

Example 3:

Input: grid = [[".","."],[".","."]]

Output: 0

Explanation:

No submatrix has at least one 'X'.

 

Constraints:

1 <= grid.length, grid[i].length <= 1000
grid[i][j] is either 'X', 'Y', or '.'.

***/


class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int>X(n),Y(n);
        for(int i = 0; i<m; i++){
            int x_cnt = 0, y_cnt = 0;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'X') x_cnt++;
                if(grid[i][j] == 'Y') y_cnt++;
                X[j] += x_cnt;
                Y[j] += y_cnt;
                if(X[j] > 0 && X[j] == Y[j]) ans++;
            }
        }
        return ans;
    }
};
