//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0022_GENERATE_PARENTHESES_H
#define LEETCODE__0022_GENERATE_PARENTHESES_H


class _0022_Generate_Parentheses {

    class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            ans.clear();
            anAns.clear();
            numPair = n;
            makeParentheses(0, 0);
            return ans;
        }
        void makeParentheses(int numL, int numR) {
            if (numR == numPair) {
                ans.push_back(anAns);
                return;
            }
            if (numL < numPair) {
                anAns.push_back('(');
                makeParentheses(numL + 1, numR);
                anAns.pop_back();
            }
            if (numR < numL) {
                anAns.push_back(')');
                makeParentheses(numL, numR + 1);
                anAns.pop_back();
            }
        }
    private:
        string anAns;
        vector<string> ans;
        int numPair;
    };

};


#endif //LEETCODE__0022_GENERATE_PARENTHESES_H
