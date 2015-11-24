//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0032_LONGEST_VALID_PARENTHESES_H
#define LEETCODE__0032_LONGEST_VALID_PARENTHESES_H


class _0032_Longest_Valid_Parentheses {

    class Solution {
    public:
        int longestValidParentheses(string s) {
            stack<int> st;
            for (int i = 0; i < s.length(); i++) {
                if (st.empty()) {
                    st.push(i);
                } else {
                    if (s[i] == '(') {
                        st.push(i);
                    } else {
                        if (s[st.top()] == '(') {
                            st.pop();
                        } else {
                            st.push(i);
                        }
                    }
                }
            }
            if (st.empty()) {
                return s.length();
            } else {
                vector<int> v;
                v.push_back(s.length());
                while (!st.empty()) {
                    v.push_back(st.top());
                    st.pop();
                }
                v.push_back(-1);
                int max = -1;
                for (int i = 0; i < v.size() - 1; i++) {
                    if (v[i] - v[i + 1] - 1 > max) max = v[i] - v[i + 1] - 1;
                }
                return max;
            }
        }
    };

};


#endif //LEETCODE__0032_LONGEST_VALID_PARENTHESES_H
