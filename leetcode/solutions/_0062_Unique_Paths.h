//
// Created by 伟平 on 2015/11/25.
//

#ifndef LEETCODE__0062_UNIQUE_PATHS_H
#define LEETCODE__0062_UNIQUE_PATHS_H


class _0062_Unique_Paths {

    class Solution {
    public:
        int uniquePaths(int m, int n) {
            int ** dp;
            dp = new int * [m];
            for (int i = 0; i < m; i++) dp[i] = new int[n];
            for (int i = 0; i < m; i++) dp[i][0] = 1;
            for (int i = 0; i < n; i++) dp[0][i] = 1;
            for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
            int ans = dp[m - 1][n - 1];
            for (int i = 0; i < m; i++) delete[] dp[i];
            delete[] dp;
            return ans;
        }
    };

};


#endif //LEETCODE__0062_UNIQUE_PATHS_H
