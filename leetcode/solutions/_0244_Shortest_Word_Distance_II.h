//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0244_SHORTEST_WORD_DISTANCE_II_H
#define LEETCODE__0244_SHORTEST_WORD_DISTANCE_II_H


class _0244_Shortest_Word_Distance_II {

    class WordDistance {
    public:
        WordDistance(vector<string>& words) {
            dis.clear();
            for (int i = words.size() - 1; i >= 0; i--) {
                map<string, vector<int> >::iterator iter = dis.find(words[i]);
                if (iter != dis.end()) iter->second.push_back(i);
                else dis[words[i]] = vector<int>(1, i);
            }
        }

        int shortest(string word1, string word2) {
            int ans = INT_MAX;
            map<string, vector<int> >::iterator iter1 = dis.find(word1);
            map<string, vector<int> >::iterator iter2 = dis.find(word2);
            for (int p = iter1->second.size() - 1, q = iter2->second.size() - 1; p >= 0 && q >= 0;) {
                int pos1 = iter1->second[p];
                int pos2 = iter2->second[q];
                if (pos1 < pos2) {
                    ans = min(ans, pos2 - pos1);
                    p--;
                }
                else {
                    ans = min(ans, pos1 - pos2);
                    q--;
                }
            }
            return ans;
        }
    private:
        map<string, vector<int> > dis;
    };

};


#endif // LEETCODE__0244_SHORTEST_WORD_DISTANCE_II_H
