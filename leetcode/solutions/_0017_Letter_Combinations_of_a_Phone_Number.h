//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
#define LEETCODE__0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H


class _0017_Letter_Combinations_of_a_Phone_Number {

    class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            possible_val[2] = "abc";
            possible_val[3] = "def";
            possible_val[4] = "ghi";
            possible_val[5] = "jkl";
            possible_val[6] = "mno";
            possible_val[7] = "pqrs";
            possible_val[8] = "tuv";
            possible_val[9] = "wxyz";
            go = digits;
            dfs(0);
            return ans;
        }
        void dfs(int pos) {
            if (pos == go.size()) {
                ans.push_back(one_ans);
                return;
            } else {
                for (int i = 0; i < possible_val[go[pos] - '0'].size(); i++) {
                    one_ans += possible_val[go[pos] - '0'][i];
                    dfs(pos + 1);
                    one_ans.erase(pos, 1);
                }
            }
        }
    private:
        string go;
        vector<string> ans;
        string one_ans;
        string possible_val[10];
    };

};


#endif //LEETCODE__0017_LETTER_COMBINATIONS_OF_A_PHONE_NUMBER_H
