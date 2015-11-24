//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0014_LONGEST_COMMON_PREFIX_H
#define LEETCODE__0014_LONGEST_COMMON_PREFIX_H


class _0014_Longest_Common_Prefix {

    class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if (strs.size() == 0) return "";
            string prefix;
            int pos = 0;
            char commonChar;
            while (1) {
                commonChar = strs[0][pos];
                if (commonChar == '\0') return prefix;
                for (int i = 1; i < strs.size(); i++) {
                    if (strs[i][pos] != commonChar) return prefix;
                }
                prefix.push_back(commonChar);
                pos++;
            }
        }
    };

};


#endif //LEETCODE__0014_LONGEST_COMMON_PREFIX_H
