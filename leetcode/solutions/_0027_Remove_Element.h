//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0027_REMOVE_ELEMENT_H
#define LEETCODE__0027_REMOVE_ELEMENT_H


class _0027_Remove_Element {

    class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
            int * A = &nums[0];
            return removeElement(A, nums.size(), val);
        }
        int removeElement(int A[], int n, int elem) {
            int i, j;
            for (i = 0, j = 0; i < n; i++) {
                if (A[i] != elem){
                    A[j++] = A[i];
                }
            }
            return j;
        }
    };

};


#endif //LEETCODE__0027_REMOVE_ELEMENT_H
