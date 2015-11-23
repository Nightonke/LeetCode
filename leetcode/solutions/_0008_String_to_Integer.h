//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0008_STRING_TO_INTEGER__ATOI__H
#define LEETCODE__0008_STRING_TO_INTEGER__ATOI__H


class _0008_String_to_Integer {

    class Solution {
    public:
        int atoi(const char *str) {
            int p = 1;
            int i = 0;
            while (str[i] == ' ') i++;  // ignore the leading blank
            if (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9')) return 0;  // if the first character is not valid
            if (str[i] == '+' || str[i] == '-') {
                if (str[i] == '-') p = -1;
                i++;
                if (str[i] < '0' || str[i] > '9') return 0;  // if the first character after the plus or minus sign is invalid
            }
            string num;
            while ('0' <= str[i] && str[i] <= '9') {
                num.push_back(str[i++]);
            }
            if (num.size() > 10) return (p == 1 ? 2147483647 : -2147483648);
            if (num.size() == 10) {
                if (p == 1 && num >= "2147483647") return 2147483647;
                if (p == -1 && num >= "2147483648") return -2147483648;
            }
            int ans = 0;
            for (int i = 0; i < num.size(); i++) {
                ans = ans * 10 + num[i] - '0';
            }
            return p * ans;
        }
    };

};


#endif //LEETCODE__0008_STRING_TO_INTEGER__ATOI__H
