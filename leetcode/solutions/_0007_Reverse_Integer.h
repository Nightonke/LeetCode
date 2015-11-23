//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0007_REVERSE_INTEGER_H
#define LEETCODE__0007_REVERSE_INTEGER_H


class _0007_Reverse_Integer {

    class Solution {
    public:
        int reverse(int x) {
            int positive = 1;
            if (x < 0) {
                positive = -1;
                x = -x;
            }
            long long int ans = 0;
            while (x) {
                ans = ans * 10 + x % 10;
                x /= 10;
            }
            if (ans < INT_MIN || ans > INT_MAX) return 0;
            return ans * positive;
        }
    };

};


#endif //LEETCODE__0007_REVERSE_INTEGER_H
