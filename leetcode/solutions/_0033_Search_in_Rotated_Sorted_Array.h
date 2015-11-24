//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H
#define LEETCODE__0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H


class _0033_Search_in_Rotated_Sorted_Array {

    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int * A = &nums[0];
            return search(A, nums.size(), target);
        }
        int search(int A[], int n, int target) {
            int low = 0, high = n - 1, mid, range = -1;
            if (A[0] > A[n - 1]) {
                while (high - low > 1) {
                    mid = low + (high - low) / 2;
                    if (A[mid] > A[high]) {
                        low = mid;
                    } else if (A[mid] < A[low]) {
                        high = mid;
                    } else {
                        return mid;
                    }
                }
                range = low;
            }
            if (target > A[n - 1]) {
                low = 0;
                high = range;
            } else {
                low = range + 1;
                high = n - 1;
            }
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (A[mid] == target) {
                    return mid;
                } else if (A[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return -1;
        }
    };

};


#endif //LEETCODE__0033_SEARCH_IN_ROTATED_SORTED_ARRAY_H
