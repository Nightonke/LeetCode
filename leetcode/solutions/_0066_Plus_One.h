//
// Created by 伟平 on 2015/11/25.
//

#ifndef LEETCODE__0066_PLUS_ONE_H
#define LEETCODE__0066_PLUS_ONE_H


class _0066_Plus_One {

    class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            digits.insert(digits.begin(), 0);
            digits[digits.size() - 1] ++;
            for (int i = digits.size() - 1; i > 0; i--) {
                digits[i - 1] += digits[i] / 10;
                digits[i] %= 10;
            }
            if (digits[0] == 0) {
                digits.erase(digits.begin());
            }
            return digits;
        }
    };

};


#endif //LEETCODE__0066_PLUS_ONE_H
