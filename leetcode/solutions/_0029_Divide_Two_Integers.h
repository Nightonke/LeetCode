//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0029_DIVIDE_TWO_INTEGERS_H
#define LEETCODE__0029_DIVIDE_TWO_INTEGERS_H


class _0029_Divide_Two_Integers {

    class Solution {
    public:
        int divide(long long int dividend, long long int divisor) {
            long long int positive = 1;
            if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
                positive = -1;
            }
            if (dividend < 0) dividend = -dividend;
            if (divisor < 0) divisor = -divisor;
            long long int r = 0;
            long long int c = divisor;
            while (dividend > c) {
                c <<= 1;
            }
            while (c >= divisor) {
                r <<= 1;
                if (dividend >= c) {
                    r++;
                    dividend -= c;
                }
                c >>= 1;
            }
            if (r * positive < -2147483648 || r * positive > 2147483647)
                return 2147483647;
            return r * positive;
        }
    };

};


#endif //LEETCODE__0029_DIVIDE_TWO_INTEGERS_H
