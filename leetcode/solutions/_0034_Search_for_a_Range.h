//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0034_SEARCH_FOR_A_RANGE_H
#define LEETCODE__0034_SEARCH_FOR_A_RANGE_H


class _0034_Search_for_a_Range {

    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int * A = &nums[0];
            return searchRange(A, nums.size(), target);
        }
        vector<int> searchRange(int A[], int n, int target) {
            vector<int> ans;
            ans.push_back(find2Side(true, A, n, target));
            ans.push_back(find2Side(false, A, n, target));
            return ans;
        }
        int find2Side (bool findLeftSide, int A[], int n, int target) {
            int low = 0, high = n - 1, mid;
            while (low <= high) {
                mid = low + (high - low) / 2;
                if (A[mid] == target) {
                    if (findLeftSide) {  // 如果找左界
                        if (mid == 0 || (A[mid - 1] != target)) {  // 符合左界情况
                            return mid;
                        } else {
                            high = mid - 1;  // 否则往左边找
                            continue;
                        }
                    }
                    if (!findLeftSide) {
                        if (mid == n - 1 || (A[mid + 1] != target)) {
                            return mid;
                        } else {
                            low = mid + 1;
                            continue;
                        }
                    }

                }
                if (A[mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return -1;
        }
    };

};


#endif //LEETCODE__0034_SEARCH_FOR_A_RANGE_H
