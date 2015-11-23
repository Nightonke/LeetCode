//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0006_ZIGZAG_CONVERSION_H
#define LEETCODE__0006_ZIGZAG_CONVERSION_H


class _0006_ZigZag_Conversion {

    class Solution {
    public:
        string convert(string s, int nRows) {
            if (nRows == 1) return s;
            string ans;
            for (int i = 0; i < s.size(); i += (nRows - 1) * 2) ans.push_back(s[i]);
            for (int i = 1; i < nRows - 1; i++) {
                int a_n = i;
                int b_n = (nRows - 1) * 2 - i;
                while (a_n < s.size() || b_n < s.size()) {
                    if (a_n < s.size()) {
                        ans.push_back(s[a_n]);
                        a_n += (nRows - 1) * 2;
                    }
                    if (b_n < s.size()) {
                        ans.push_back(s[b_n]);
                        b_n += (nRows - 1) * 2;
                    }
                }
            }
            for (int i = nRows - 1; i < s.size(); i += (nRows - 1) * 2) ans.push_back(s[i]);
            return ans;
        }
    };

};


#endif //LEETCODE__0006_ZIGZAG_CONVERSION_H
