//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0042_TRAPPING_RAIN_WATER_H
#define LEETCODE__0042_TRAPPING_RAIN_WATER_H


class _0042_Trapping_Rain_Water {

    class Solution {
    public:
        int trap(vector<int>& height) {
            int * A = &height[0];
            return trap(A, height.size());
        }
        int trap(int A[], int n) {
            int * lmax = new int[n];
            int * rmax = new int[n];
            for (int i = 0, Max = -1; i < n; i++) lmax[i] = Max = max(A[i], Max);
            for (int i = n - 1, Max = -1; i >= 0; i--) rmax[i] = Max = max(A[i], Max);
            int ans = 0;
            for (int i = 0; i < n; i++) ans += min(lmax[i], rmax[i]) - A[i];
            delete []lmax;
            delete []rmax;
            return ans;
        }
    };

};


#endif //LEETCODE__0042_TRAPPING_RAIN_WATER_H
