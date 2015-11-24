//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0043_MULTIPLY_STRINGS_H
#define LEETCODE__0043_MULTIPLY_STRINGS_H


class _0043_Multiply_Strings {

    class Solution {
    public:
        string multiply(string num1, string num2) {
            string ans(num1.length() + num2.length() + 1, 0);
            reverse(num1.begin(), num1.end());
            reverse(num2.begin(), num2.end());
            for (int i = 0; i < num1.size(); i++) num1[i] -= '0';
            for (int i = 0; i < num2.size(); i++) num2[i] -= '0';
            for (int i = 0; i < num1.length(); i++) {
                for (int j = 0; j < num2.length(); j++) {
                    ans[i + j] += num1[i] * num2[j];
                    ans[i + j + 1] += ans[i + j] / 10;
                    ans[i + j] %= 10;
                }
            }
            int i;
            for (i = num1.length() + num2.length(); i > 0 && ans[i] == 0; i--);
            ans = ans.substr(0, i + 1);
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) ans[i] += '0';
            return ans;
        }
    };

};


#endif //LEETCODE__0043_MULTIPLY_STRINGS_H
