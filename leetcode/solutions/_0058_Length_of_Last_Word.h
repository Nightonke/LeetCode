//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0058_LENGTH_OF_LAST_WORD_H
#define LEETCODE__0058_LENGTH_OF_LAST_WORD_H


class _0058_Length_of_Last_Word {

    class Solution {
    public:
        int lengthOfLastWord(string s) {
            char * S = &s[0];
            return lengthOfLastWord(S);
        }
        int lengthOfLastWord(const char *s) {
            int length, i;
            for (length = 0; s[length] != '\0'; length++);
            for (; s[length - 1] == ' '; length--);
            for (i = length - 1; i >= 0 && s[i] != ' '; i--);
            return length - i - 1;
        }
    };

};


#endif //LEETCODE__0058_LENGTH_OF_LAST_WORD_H
