//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0035_SEARCH_INSERT_POSITION_H
#define LEETCODE__0035_SEARCH_INSERT_POSITION_H


class _0035_Search_Insert_Position {

    class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int * A = &nums[0];
            return searchInsert(A, nums.size(), target);
        }
        int searchInsert(int A[], int n, int target) {
            int low = 0, high = n - 1, mid;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (A[mid] == target) return mid;
                else if (A[mid] < target) low = mid + 1;
                else high = mid - 1;
            }
            return high + 1;
        }
    };

};


#endif //LEETCODE__0035_SEARCH_INSERT_POSITION_H
