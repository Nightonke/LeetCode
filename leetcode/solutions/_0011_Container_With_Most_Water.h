//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0011_CONTAINER_WITH_MOST_WATER_H
#define LEETCODE__0011_CONTAINER_WITH_MOST_WATER_H


class _0011_Container_With_Most_Water {

    class Solution {
    public:
        int maxArea(vector<int> &height) {
            int i = 0, j = height.size() - 1, ans = 0;
            while (i < j) {
                ans = max(ans, (j - i) * min(height[i], height[j]));
                if (height[i] < height[j]) i++;
                else j--;
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0011_CONTAINER_WITH_MOST_WATER_H
