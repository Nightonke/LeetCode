//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
#define LEETCODE__0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H


class _0026_Remove_Duplicates_from_Sorted_Array {

    class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int * A = &nums[0];
            return oldRemoveDuplicates(A, nums.size());
        }
        int oldRemoveDuplicates(int A[], int n) {
            if (!n) return 0;
            int cmp[n];
            cmp[0] = A[0];
            int counter = 1;
            for (int i = 1; i < n; i++) {
                if (cmp[counter - 1] != A[i]) {
                    cmp[counter++] = A[i];
                }
            }
            for (int i = 0; i < counter; i++) A[i] = cmp[i];
            return counter;
        }
    };

};


#endif //LEETCODE__0026_REMOVE_DUPLICATES_FROM_SORTED_ARRAY_H
