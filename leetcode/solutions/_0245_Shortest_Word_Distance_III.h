//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0245_SHORTEST_WORD_DISTANCE_III_H
#define LEETCODE__0245_SHORTEST_WORD_DISTANCE_III_H


class _0245_Shortest_Word_Distance_III {

    class Solution {
    public:
        int shortestWordDistance(vector<string>& words,
            string word1, string word2) {

            int ans = words.size(), p = -1, q = -1;

            for (int i = words.size() - 1; i >= 0; i--) {
                if (word1 == words[i]) p = i;
                if (p != -1 && q != -1 && p != q) ans = min(abs(p - q), ans);
                if (word2 == words[i]) q = i;
                if (p != -1 && q != -1 && p != q) ans = min(abs(p - q), ans);
            }

            return ans;
        }
    };

};


#endif // LEETCODE__0245_SHORTEST_WORD_DISTANCE_III_H
