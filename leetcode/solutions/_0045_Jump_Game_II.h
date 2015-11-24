//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0045_JUMP_GAME_II_H
#define LEETCODE__0045_JUMP_GAME_II_H


class _0045_Jump_Game_II {

    class Solution {
    public:
        int jump(vector<int>& nums) {
            int * A = &nums[0];
            return jump(A, nums.size());
        }
        int jump(int A[], int n) {
            int * step = new int[n];
            step[0] = 0;
            int pos = 1;
            for (int i = 0; i < n; i++) {
                int j;
                for (j = pos; j <= A[i] + i && j < n; j++) {
                    step[j] = step[i] + 1;
                }
                pos = j;
            }
            int ans = step[n - 1];
            delete []step;
            return ans;
        }
    };

};


#endif //LEETCODE__0045_JUMP_GAME_II_H
