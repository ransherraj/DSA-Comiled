/***

128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
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
