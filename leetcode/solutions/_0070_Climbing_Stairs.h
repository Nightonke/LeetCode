//
// Created by 伟平 on 2015/11/25.
//

#ifndef LEETCODE__0070_CLIMBING_STAIRS_H
#define LEETCODE__0070_CLIMBING_STAIRS_H


class _0070_Climbing_Stairs {

    class Solution {
    public:
        int climbStairs(int n) {
            vector<int> s(n + 5);
            s[0] = 1;
            s[1] = 1;
            for (int i = 2; i <= n; i++) {
                s[i] = s[i - 1] + s[i - 2];
            }
            return s[n];
        }
    };

};


#endif //LEETCODE__0070_CLIMBING_STAIRS_H
