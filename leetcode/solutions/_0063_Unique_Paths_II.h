//
// Created by 伟平 on 2015/11/25.
//

#ifndef LEETCODE__0063_UNIQUE_PATHS_II_H
#define LEETCODE__0063_UNIQUE_PATHS_II_H


class _0063_Unique_Paths_II {

    class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            vector<vector<int> > dp(obstacleGrid.size());
            for (int i = 0 ; i < dp.size(); i++) dp[i].resize(obstacleGrid[i].size());
            if (obstacleGrid[0][0] == 1) return 0;
            else dp[0][0] = 1;
            for (int i = 1; i < dp[0].size(); i++) {
                if (obstacleGrid[0][i] == 1) dp[0][i] = 0;
                else dp[0][i] = dp[0][i - 1];
            }
            for (int i = 1; i < dp.size(); i++) {
                if (obstacleGrid[i][0] == 1) dp[i][0] = 0;
                else dp[i][0] = dp[i - 1][0];
            }
            for (int i = 1; i < dp.size(); i++) {
                for (int j = 1; j < dp[i].size(); j++) {
                    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
            return dp[dp.size() - 1][dp[dp.size() - 1].size() - 1];
        }
    };

};


#endif //LEETCODE__0063_UNIQUE_PATHS_II_H
