//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0263_UGLY_NUMBER_H
#define LEETCODE__0263_UGLY_NUMBER_H


class _0263_Ugly_Number {

    class Solution {
    public:
        bool isUgly(int num) {
            for (int i = 2; i < 6 && num; i++)while (num % i == 0) num /= i;
            return num == 1;
        }
    };

};


#endif // LEETCODE__0263_UGLY_NUMBER_H
