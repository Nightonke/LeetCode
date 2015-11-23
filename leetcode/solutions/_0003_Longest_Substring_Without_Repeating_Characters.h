//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define LEETCODE__0003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H


class _0003_Longest_Substring_Without_Repeating_Characters {

    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int maxDis = 0, newDis = 0;
            int latestPos[256];
            for (int i = 0; i < 256; latestPos[i++] = -1);
            for (int i = 0; i < s.size(); i++) {
                if (latestPos[s[i]] == -1 ||latestPos[s[i]] < i - newDis)
                    newDis++;
                else
                    newDis = i - latestPos[s[i]];
                latestPos[s[i]] = i;
                if (newDis > maxDis) maxDis = newDis;
            }
            return maxDis;
        }
    };

};


#endif //LEETCODE__0003_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
