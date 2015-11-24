//
// Created by 伟平 on 2015/11/25.
//

#ifndef LEETCODE__0064_MINIMUM_PATH_SUM_H
#define LEETCODE__0064_MINIMUM_PATH_SUM_H


class _0064_Minimum_Path_Sum {

    class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            vector<vector<int> > dp(grid.size());
            for (int i = 0; i < dp.size(); i++) dp[i].resize(grid[i].size());
            dp[0][0] = grid[0][0];
            for (int i = 1; i < dp[0].size(); i++) {
                dp[0][i] = dp[0][i - 1] + grid[0][i];
            }
            for (int i = 1; i < dp.size(); i++) {
                dp[i][0] = dp[i - 1][0] + grid[i][0];
            }
            for (int i = 1; i < dp.size(); i++) {
                for (int j = 1; j < dp[i].size(); j++) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
            return dp[dp.size() - 1][dp[dp.size() - 1].size() - 1];
        }
    };

};


#endif //LEETCODE__0064_MINIMUM_PATH_SUM_H
