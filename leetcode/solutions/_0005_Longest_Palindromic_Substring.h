//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0005_LONGEST_PALINDROMIC_SUBSTRING_H
#define LEETCODE__0005_LONGEST_PALINDROMIC_SUBSTRING_H


class _0005_Longest_Palindromic_Substring {

    class Solution {
    public:
        string longestPalindrome(string s) {
            int max = 0, maxS, maxE;
            for (int i = 0; i < s.size(); i++) {
                int i1, i2, temp = 1;
                for (i1 = i - 1, i2 = i + 1; i1 >= 0 && i2 < s.size() && s[i1] == s[i2]; i1--, i2++) temp += 2;
                if (temp > max) {
                    max = temp;
                    maxS = i1 + 1;
                    maxE = i2 - 1;
                }
                temp = 0;
                for (i1 = i, i2 = i + 1; i1 >= 0 && i2 < s.size() && s[i1] == s[i2]; i1--, i2++) temp += 2;
                if (temp > max) {
                    max = temp;
                    maxS = i1 + 1;
                    maxE = i2 - 1;
                }
            }
            return s.substr(maxS, maxE - maxS + 1);
        }
    };

};


#endif //LEETCODE__0005_LONGEST_PALINDROMIC_SUBSTRING_H
