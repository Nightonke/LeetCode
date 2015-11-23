//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0009_PALINDROME_NUMBER_H
#define LEETCODE__0009_PALINDROME_NUMBER_H


class _0009_Palindrome_Number {

    class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
            long long int i, j = 10;
            for (i = 10; x / i; i *= 10);
            if (x == 0) i *= 10;
            for (; j < i; i /= 10, j *= 10) {
                if ((x % i) / (i / 10) != (x % j) / (j / 10)) return false;
            }
            return true;
        }
    };

};


#endif //LEETCODE__0009_PALINDROME_NUMBER_H
