//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0020_VALID_PARENTHESES_H
#define LEETCODE__0020_VALID_PARENTHESES_H


class _0020_Valid_Parentheses {

    class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for (int i = 0; i < s.size(); i++) {
                if (st.empty()) st.push(s[i]);
                else if (0 < s[i] - st.top() && s[i] - st.top() < 3) st.pop();
                else st.push(s[i]);
            }
            return st.empty();
        }
    };

};


#endif //LEETCODE__0020_VALID_PARENTHESES_H
