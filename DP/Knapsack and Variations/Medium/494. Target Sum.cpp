/***

494. Target Sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

**/


class Solution {
public:

    int tergetSum(vector<int>& nums, int target){
        int n = nums.size();
        int dp[n+1][target+1];

        dp[0][0] = 1;
        // sum for n = 0 is always 0
        for(int i = 1; i<target+1; i++){
            dp[0][i] = 0;
        }

        // ***no of way to get sum = 0 for all n is alwyas 1 (important)
        // for(int i = 0; i<target+1; i++){
        //     dp[i][0] = 1;
        // }

        for(int i = 1; i<n+1; i++){
            for(int j = 0; j<target+1; j++){
                if(nums[i - 1] <= j){
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j - nums[i-1]]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][target];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum || (sum + target) % 2 != 0) return 0;

        int s1 = (sum + target) / 2;

        int ans = tergetSum(nums, s1);

        return ans;
    }
};
