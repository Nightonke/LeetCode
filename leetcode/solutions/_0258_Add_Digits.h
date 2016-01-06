//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0258_ADD_DIGITS_H
#define LEETCODE__0258_ADD_DIGITS_H


class _0258_Add_Digits {

    // https://en.wikipedia.org/wiki/Digital_root
    class Solution {
    public:
        int addDigits(int num) {
            return num - 9 * ((num - 1) / 9);
        }
    };

};


#endif // LEETCODE__0258_ADD_DIGITS_H
