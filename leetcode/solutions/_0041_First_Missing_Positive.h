//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0041_FIRST_MISSING_POSITIVE_H
#define LEETCODE__0041_FIRST_MISSING_POSITIVE_H


class _0041_First_Missing_Positive {

    class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            int * A = &nums[0];
            return firstMissingPositive(A, nums.size());
        }
        int firstMissingPositive(int A[], int n) {
            if (n == 0) return 1;
            //if (n == 1) return A[0] == 1 ? 2 : 1;
            int last;
            for (int i = 0; i < n; i++) {
                int target = A[i];

                while (0 <= target && target < n && target != A[target]) {
                    swap(target, A[target]);
                }
                if (target == n) last = target;
            }
            for (int i = 1; i <= n; i++) {
                if (i == n) {
                    if (last != i) return i;
                    else return n + 1;
                }
                if (A[i] != i) return i;
            }
            return n;
        }
    };

};


#endif //LEETCODE__0041_FIRST_MISSING_POSITIVE_H
