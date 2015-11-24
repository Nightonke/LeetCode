//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0016_3SUM_CLOSEST_H
#define LEETCODE__0016_3SUM_CLOSEST_H


class _0016_3Sum_Closest {

    class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            int ans;
            int error;
            int min_error = 999999;
            for (int i = 0; i < num.size(); i++) {
                for (int j = i + 1; j < num.size(); j++) {
                    for (int k = j + 1; k < num.size(); k++) {
                        error = num[i] + num[j] + num[k] - target;
                        if (error < 0) {
                            error = -error;
                        }
                        if (error < min_error) {
                            ans = num[i] + num[j] + num[k];
                            min_error = error;
                        }
                        if (error == 0) {
                            return target;
                        }
                    }
                }
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0016_3SUM_CLOSEST_H
