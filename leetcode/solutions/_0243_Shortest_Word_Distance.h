//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0243_SHORTEST_WORD_DISTANCE_H
#define LEETCODE__0243_SHORTEST_WORD_DISTANCE_H


class _0243_Shortest_Word_Distance {

    class Solution {
    public:
        int shortestDistance(vector<string>& words,
            string word1, string word2) {

            int ans = words.size(), p = -1, q = -1;

            for (int i = words.size() - 1; i >= 0; i--) {
                if (word1 == words[i]) p = i;
                if (word2 == words[i]) q = i;
                if (p != -1 && q != -1) ans = min(abs(p - q), ans);
            }

            return ans;
        }
    };

};


#endif // LEETCODE__0243_SHORTEST_WORD_DISTANCE_H
