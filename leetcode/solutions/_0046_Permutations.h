//
// Created by 伟平 on 2015/11/24.
//

#ifndef LEETCODE__0046_PERMUTATIONS_H
#define LEETCODE__0046_PERMUTATIONS_H


class _0046_Permutations {

    class Solution {
    public:
        vector<vector<int> > permute(vector<int> &num) {
            vector<int> n = num;
            sort(n.begin(), n.end());
            vector<int> original = n;
            vector<vector<int> > ans;
            while (1) {
                ans.push_back(n);
                next_permutation(n.begin(), n.end());
                if (original == n) break;
            }
            return ans;
        }
    };

};


#endif //LEETCODE__0046_PERMUTATIONS_H
