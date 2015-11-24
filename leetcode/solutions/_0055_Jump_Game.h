//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0055_JUMP_GAME_H
#define LEETCODE__0055_JUMP_GAME_H


class _0055_Jump_Game {

    class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int * A = &nums[0];
            return canJump(A, nums.size());
        }
        bool canJump(int A[], int n) {
            int canReach = 0;  // the original canReach point is the starting point
            for (int i = 0; i < n && i <= canReach; i++) {
                if (i + A[i] > canReach) canReach = i + A[i];
                if (canReach >= n - 1) return true;
            }
            return canReach >= n - 1;
        }
    };

};


#endif //LEETCODE__0055_JUMP_GAME_H
