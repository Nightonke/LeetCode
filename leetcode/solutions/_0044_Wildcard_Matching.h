//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0044_WILDCARD_MATCHING_H
#define LEETCODE__0044_WILDCARD_MATCHING_H


class _0044_Wildcard_Matching {

    class Solution {
    public:
        bool isMatch(string s, string p) {
            char * S = &s[0], * P = &p[0];
            return isMatch(S, P);
        }
        bool isMatch(const char * s, const char * p) {
            int posOfStar = -1;  // p中最近一次*号的位置
            int posOfTail = 0;  // 在s中被p中用*号代替的子字符串的串尾的下一位
            int si = 0;
            int pi = 0;

            while (s[si] != '\0') {

                //如果匹配上了都往下一位
                if (p[pi] == '?' || p[pi] == s[si]) {
                    pi++;
                    si++;
                    continue;
                }

                //如果p中出现了*，第一更新posOfStar，说明有*号可以在不得已的时候使用（也就是下一步）
                if (p[pi] == '*') {
                    posOfStar = pi;
                    pi++;  // 同时pi往下移动准备下次匹配
                    posOfTail = si;  // 这个时候说明被*号代替的子字符串长度为0
                    continue;
                }

                //如果这个时候既不匹配，pi位置上也没有*，说明走投无路了，为了尽量匹配只好用之前出现过的*来代替s中不匹配的内容
                if (posOfStar != -1) {
                    pi = posOfStar + 1;  // 因此pi位置要重新返回到*号的下一位准备上述代替后的匹配
                    posOfTail++;  // 那么s中被p中用*号代替的子字符串增加一位
                    si = posOfTail;  // 同时下一次si的起始点也后移，后移到在s中被p中用*号代替的子字符串的串尾的下一位，也就是下一次匹配的开始位
                    continue;
                }

                //如果运行到这一步说明没有任何办法匹配了
                return false;
            }

            while (p[pi] == '*') pi++;  // 因为上述循环在s用完的时候就结束了，我们要检查p中的剩余元素，*可以代表没元素，因此可跳过

            return p[pi] == '\0';  // 如果p中还有剩余就不匹配了

        }
    };

};


#endif //LEETCODE__0044_WILDCARD_MATCHING_H
