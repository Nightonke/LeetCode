//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0028_IMPLEMENT_STRSTR___H
#define LEETCODE__0028_IMPLEMENT_STRSTR___H


class _0028_Implement_strStr__ {

    class Solution {
    public:
        int strStr(string haystack, string needle) {
            char * h = &haystack[0], * n = &needle[0];
            return BoyerMoore(n, h);
        }
        char *strStr(char *haystack, char *needle) {
            int i = BoyerMoore(needle, haystack);
            if (i == -1) return NULL;
            else return haystack + i;
        }

        void suffixes(char * pattern, vector<int> & suffixes) {
            suffixes[lengthOfPattern - 1] = lengthOfPattern;
            int g = lengthOfPattern - 1;
            int f;

            for (int i = lengthOfPattern - 2; i >= 0; i--) {
                if (i > g && suffixes[i + lengthOfPattern - 1 - f] < i - g) {
                    suffixes[i] = suffixes[i + lengthOfPattern - 1 - f];
                } else {
                    if (i < g) {
                        g = i;
                    }
                    f = i;

                    while (g >= 0 && pattern[g] == pattern[g + lengthOfPattern - 1 - f]) {
                        g--;
                    }
                    suffixes[i] = f - g;
                }
            }
        }

        void findBadCharacters(char * pattern, vector<int> & badCharacters) {

            for (int i = 0; i < lengthOfPattern - 1; i++) {
                badCharacters[pattern[i]] = lengthOfPattern - i - 1;
            }
        }

        void findGoodSuffixes(char * pattern, vector<int> & goodSuffixes) {
            vector<int> suff(lengthOfPattern, 0);

            suffixes(pattern, suff);

            for (int i = 0; i < lengthOfPattern; i++) {
                goodSuffixes[i] = lengthOfPattern;
            }

            int j = 0;
            for (int i = lengthOfPattern - 1; i >= 0; i--) {
                if (suff[i] == i + 1) {
                    for (; j < lengthOfPattern - i - 1; j++) {
                        if (goodSuffixes[j] == lengthOfPattern) {
                            goodSuffixes[j] = lengthOfPattern - i - 1;
                        }
                    }
                }
            }

            for (int i = 0; i <= lengthOfPattern - 2; i++) {
                goodSuffixes[lengthOfPattern - 1 - suff[i]] = lengthOfPattern - i - 1;
            }
        }

        int BoyerMoore(char * pattern, char * text) {
            lengthOfText = strlen(text);
            lengthOfPattern = strlen(pattern);

            // some specil cases
            if (lengthOfPattern == 0 && lengthOfText == 0) return 0;
            if (lengthOfPattern == lengthOfText) {
                for (int i = 0; i < lengthOfText; i++) {
                    if (pattern[i] != text[i]) return -1;
                }
                return 0;
            }
            if (lengthOfPattern == 0) return lengthOfText - 1;
            if (lengthOfText == 0) return -1;

            goodSuffixes.resize(lengthOfPattern);
            badCharacters.resize(256);

            findGoodSuffixes(pattern, goodSuffixes);
            findBadCharacters(pattern, badCharacters);

            int j = 0;
            while (j <= lengthOfText - lengthOfPattern) {
                int i;
                for (i = lengthOfPattern - 1; i >= 0 && pattern[i] == text[i + j]; i--);
                if (i < 0) {
                    return j;  // return the first matching position
                    //cout << j << endl;  // output every position that is the head of a matching
                    j += goodSuffixes[0];
                } else {
                    j += max(goodSuffixes[i], badCharacters[text[i + j]] - lengthOfPattern + i + 1);
                }
            }
            return -1;
        }

    private:
        vector<int> goodSuffixes;
        vector<int> badCharacters;
        int lengthOfPattern;
        int lengthOfText;
    };

};


#endif //LEETCODE__0028_IMPLEMENT_STRSTR___H
