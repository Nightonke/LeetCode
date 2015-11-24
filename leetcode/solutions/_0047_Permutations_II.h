//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0047_PERMUTATIONS_II_H
#define LEETCODE__0047_PERMUTATIONS_II_H


class _0047_Permutations_II {

    class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            vector<int> n = num;
            sort(n.begin(), n.end());
            vector<int> ori = n;
            vector<vector<int> > ans;
            while (1) {
                ans.push_back(n);
                next_permutation(n.begin(), n.end());
                if (n == ori) break;
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0047_PERMUTATIONS_II_H
