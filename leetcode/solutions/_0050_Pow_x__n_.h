//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0050_POW_X__N__H
#define LEETCODE__0050_POW_X__N__H


class _0050_Pow_x__n_ {

    class Solution {
    public:
        double myPow(double x, int n) {
            if (n < 0) {
                x = 1 / x;
                n = -n;
            }
            if (n == 1) return x;
            if (n == 0) return 1.0;

            if (n & 1 == 1) {
                return x * pow(x, n - 1);
            } else {
                double temp = pow(x, n / 2);
                return temp * temp;
            }
        }
    };

};


#endif //LEETCODE__0050_POW_X__N__H
