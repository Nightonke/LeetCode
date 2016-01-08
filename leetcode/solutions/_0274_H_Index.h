//
// Created by Weiping Huang on 2015/11/25.
//

#ifndef LEETCODE__0274_H_INDEX_H
#define LEETCODE__0274_H_INDEX_H


class _0274_H_Index {

    class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int size = citations.size();
            if (size == 0) return 0;
            vector<int> posibleAnswer(size + 1);
            for (int i = 0; i < size; i++) {
                if (citations[i] > size) posibleAnswer[size]++;
                else posibleAnswer[citations[i]]++;
            }
            int counter = 0;
            for (int i = size; i >= 0; i--) {
                counter += posibleAnswer[i];
                if (counter >= i) return i;
            }
            return 0;
        }
    };

};


#endif // LEETCODE__0274_H_INDEX_H
