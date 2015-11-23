//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0010_REGULAR_EXPRESSION_MATCHING_H
#define LEETCODE__0010_REGULAR_EXPRESSION_MATCHING_H


class _0010_Regular_Expression_Matching {

    class Solution {
    public:
        bool isMatch(const char *s, const char *p) {

            if (*p == '\0') return *s == '\0';

            if (*(p + 1) == '*') {

                while (*s != '\0' && (*s == *p || *p == '.')) {

                    if (isMatch(s, p + 2)) return true;
                    s++;

                }

                return isMatch(s, p + 2);

            } else {

                if (*s != '\0' && (*s == *p || *p == '.')) return isMatch(s + 1, p + 1);

                else return false;

            }

        }
    };

};


#endif //LEETCODE__0010_REGULAR_EXPRESSION_MATCHING_H
