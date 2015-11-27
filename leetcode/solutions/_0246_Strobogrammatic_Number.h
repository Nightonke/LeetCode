//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0246_STROBOGRAMMATIC_NUMBER_H
#define LEETCODE__0246_STROBOGRAMMATIC_NUMBER_H


class _0246_Strobogrammatic_Number {

    class Solution {
    public:
        bool isStrobogrammaticChar(char a, char b) {
            return (a == '6' && b == '9')
                   || (a == '9' && b == '6')
                   || (a == '1' && b == '1')
                   || (a == '8' && b == '8')
                   || (a == '0' && b == '0');
        }
        bool isStrobogrammatic(string num) {
            for (int i = num.size() / 2; i >= 0; i--)
                if (!isStrobogrammaticChar(num[i], num[num.size() - i - 1]))
                    return false;
            return true;
        }
    };

};


#endif // LEETCODE__0246_STROBOGRAMMATIC_NUMBER_H
